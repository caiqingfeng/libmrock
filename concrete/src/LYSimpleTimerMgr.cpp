/*
 * LYSimpleTimerMgr.cpp
 *
 *  Created on: 2013-5-3
 *      Author: caiqingfeng
 */

#include "../../concrete/src/LYSimpleTimerMgr.h"

#include <boost/shared_ptr.hpp>
#include "common/src/timer.pb.h"
#include <exception>

extern LYSimpleTimerMgrPtr timerMgr;

using namespace com::luyun::timer::shared;
using namespace com::luyun::timer;

std::string peer_addr; //20150219增加，一个Concrete只给一个服务器提供定时服务，因此peer_addr为全局变量

LYSimpleTimerMgr::LYSimpleTimerMgr(zmq::socket_t& rm) :
        remote(rm)
{
    timers.clear();
}

//void LYSimpleTimerMgr::handleNW()
//{
//    unsigned int zmq_events;
//    size_t opt_len;
//
//    try
//    {
//        while (1)
//        {
//            this->remote.getsockopt(ZMQ_EVENTS, &zmq_events, &opt_len);
//
//            if (ZMQ_POLLIN & zmq_events)
//            {
//                std::string client = s_recv(this->remote); //get address
//                std::string msg = s_recv(this->remote); //get real message then
//                this->onMsg(client, msg);
//            }
//            else
//            {
//                break;
//            }
//        }
//    } catch (std::exception &e)
//    {
////		LY_LOG_ERR("fatal error happened, zmq failed!");
//        return;
//    }
//}

void LYSimpleTimerMgr::onMsg(const string &from, const string &msg)
{
    //decode msg
    LYTimerMsg timerMsg;
    std::string replyTo = from;

    if (!timerMsg.ParseFromString(msg))
    {
        LY_LOG_ERR("fatal error, decode failed");
        return;
    }
    LY_LOG_DBG("get timer message.\n" << timerMsg.DebugString());
    if (timerMsg.has_client_id())
    {
        replyTo = timerMsg.client_id();
    }
    if (!timerMsg.has_server_timer_id() && timerMsg.action() != LY_TIMER_REG)
    {
        LY_LOG_ERR("fatal error, should be register" << timerMsg.DebugString());
        return;
    }
    LYTimerPtr timerPtr;
    float after = 0.0;
    float repeat = 0.0;
    float will_stop_at = time(NULL)+60*60*48;
    if (timerMsg.has_after())
    { //because after, repeat set by new message
        after = timerMsg.after();
    }
    if (timerMsg.has_repeat())
    {
        repeat = timerMsg.repeat();
    }
    if (timerMsg.has_will_stop_at())
    {
    	will_stop_at = timerMsg.will_stop_at();
    }
    std::map<std::string, LYTimerPtr>::iterator it = timers.end();
    LYTimerMsg replyMsg = timerMsg;
    if (LY_TIMER_REG != timerMsg.action() && timerMsg.has_server_timer_id())
    {
    	if (LY_TIMER_CAN == timerMsg.action()) {
    		it = timers.find(timerMsg.server_timer_id());
    		if (it == timers.end())
    		{
    			LY_LOG_ERR("weired, not found timer in the map" << timerMsg.DebugString());
    			return;
    		}
    		timerPtr = it->second;
    	}
        replyMsg.set_server_timer_id(timerMsg.server_timer_id());
    }
    else
    { //create a new timer and put it into map
        LYTimer *timer = new LYTimer(replyTo, after, repeat);
        if (repeat > 0.0) {
        	timer->set_will_stop_at(will_stop_at);
        }
        if (timerMsg.has_client_timer_id())
        {
            timer->set_client_timer_id(timerMsg.client_timer_id());
        }
        if (timerMsg.has_second_client_timer_id())
        {
            timer->set_second_client_timer_id(
                    timerMsg.second_client_timer_id());
        }
        if (timerMsg.has_client_reserved1())
        {
            timer->set_client_reserved1(timerMsg.client_reserved1());
        }
        if (timerMsg.has_client_reserved2())
        {
            timer->set_client_reserved2(timerMsg.client_reserved2());
        }
        if (timerMsg.has_client_reserved3())
        {
            timer->set_client_reserved3(timerMsg.client_reserved3());
        }
        if (timerMsg.has_client_reserved4())
        {
            timer->set_client_reserved4(timerMsg.client_reserved4());
        }
        if (timerMsg.has_client_reserved5())
        {
            timer->set_client_reserved5(timerMsg.client_reserved5());
        }
        LYTimerPtr tp(timer);
        timerPtr = tp;
        std::ostringstream ios;
        ios << static_cast<void *>(timerPtr->getTimeout().get());
        LY_LOG_INF(ios.str());
        timers[ios.str()] = timerPtr;
        replyMsg.set_server_timer_id(ios.str());
    }
    boost::shared_ptr<long> ev_timer_ptr = timerPtr->getTimeout();
    time_t now = time(NULL);
    switch (timerMsg.action())
    {
    case LY_TIMER_REG:
    	//        ev_timer_init(ev_timer_ptr.get(), timeout_cb, after, repeat);
    	//        ev_timer_start(loop, ev_timer_ptr.get());
    case LY_TIMER_RESET: //20130814
    	//        ev_timer_stop(loop, ev_timer_ptr.get());
    	//        ev_timer_start(loop, ev_timer_ptr.get());
        timerPtr->set_next_fire_at(now+(int)after);
        break;
    case LY_TIMER_CAN:
//        ev_timer_stop(loop, ev_timer_ptr.get());
        timers.erase(it);
        return; //cancel timer doesn't send message back
        break;
    case LY_TIMER_FIRE:
    default:
        LY_LOG_ERR("wrong msg" << timerMsg.DebugString());
        return;
    }
    zmq_sendmore_wrapper(remote, replyTo);
    std::string ss;
    replyMsg.set_action(LY_TIMER_CONF);
    replyMsg.SerializeToString(&ss);
    zmq_send_wrapper(remote, ss);
    LY_LOG_DBG("confirmed message \n" << replyMsg.DebugString());
}

void LYSimpleTimerMgr::onTimeout(const string &timerId)
{
//    std::cout << timerId << std::endl;
    //find that timer by key timerId
    std::map<std::string, LYTimerPtr>::iterator it = this->timers.find(timerId);
    if (it == this->timers.end())
    { //not set before
        std::cout << "not found" << std::endl;
        LY_LOG_ERR("not found timer by key " << timerId);
        return;
    }
    LYTimerPtr tp = it->second;
//	tp->onTimeout();
    zmq_sendmore_wrapper(remote, tp->getClient());
    LYTimerMsg timeOutMsg;
    if (tp->get_repeat() > 0.0) {
		timeOutMsg.set_repeat(tp->get_repeat());
    	if (time(NULL) > tp->get_will_stop_at()){
    		timeOutMsg.set_repeat(0.0);
    	}
    } 
    timeOutMsg.set_action(LY_TIMER_FIRE);
    timeOutMsg.set_version(1);
    timeOutMsg.set_server_timer_id(timerId);
    timeOutMsg.set_client_id(tp->getClient());
    timeOutMsg.set_client_timer_id(tp->get_client_timer_id());
    timeOutMsg.set_second_client_timer_id(tp->get_second_client_timer_id());
    timeOutMsg.set_client_reserved1(tp->get_client_reserved1());
    timeOutMsg.set_client_reserved2(tp->get_client_reserved2());
    timeOutMsg.set_client_reserved3(tp->get_client_reserved3());
    timeOutMsg.set_client_reserved4(tp->get_client_reserved4());
    timeOutMsg.set_client_reserved5(tp->get_client_reserved5());
//    LY_LOG_DBG("fired timeout event \n" << timeOutMsg.DebugString());
    std::string ss;
    timeOutMsg.SerializeToString(&ss);
    zmq_send_wrapper(remote, ss);
    //delete timer to release memory
    if (tp->get_repeat() == 0.0 
    		|| (tp->get_repeat() > 0.0 && time(NULL) > tp->get_will_stop_at())){
    	if (tp->get_repeat() > 0.0) {
//    		ev_timer_stop(loop, tp->getTimeout().get());
    	}
//        timers.erase(it);
    } 
}

void LYSimpleTimerMgr::run()
{
//	std::cout << "running ...." << std::endl;
    zmq::pollitem_t items[] =
    {
            { remote, 0, ZMQ_POLLIN, 0 }
    };

    time_t last_message_from_peer = time(NULL);
    while (true)
    {
//    LY_LOG_DBG("looping");
    	time_t last_inspect = time(NULL);
        zmq::poll(&items[0], 1, 500); //timeout after 1 second
//    LY_LOG_DBG("after polling");

        if (items[0].revents & ZMQ_POLLIN)
        {
//    		std::cout << "msg arriving..." << std::endl;
            peer_addr = s_recv(this->remote); //get address
            std::string msg = s_recv(this->remote); //get real message then
            last_message_from_peer = time(NULL);
            if (msg == "shakehand") {
            	continue;
            }
            this->onMsg(peer_addr, msg);
        }

        time_t now = time(NULL);
//        if (now > (last_inspect + 1)) {
        	this->iterateAllTimers();
//        }

        if (now > last_message_from_peer+5 && now <= last_message_from_peer+15) {
        	//如果超过5s，此时需要发一个心跳包给对端，看它是否还活着？
        	this->shakeHand();
        	continue;
        }
        if (now > last_message_from_peer+15) {
        	//超过10s没有收到对端的响应，退出，以保证1－1的定时服务
        	LY_LOG_INF("peer dead, exiting ..., last message received at " << (now-last_inspect) << "s before!");
        	exit(-1);
        }
	}
}

void LYSimpleTimerMgr::shakeHand()
{
//	LY_LOG_DBG("shaking hand with peer...");

//	if (timers.size() < 1) return;
//    //find that timer by key timerId
//    std::map<std::string, LYTimerPtr>::iterator it = this->timers.begin();
//    LYTimerPtr tp = it->second;
//    s_sendmore(remote, tp->getClient());
	/* 只给一个进程提供服务
	 *
	 */
	zmq_sendmore_wrapper(remote, peer_addr);
    LYTimerMsg shakeHandMsg;
    shakeHandMsg.set_action(LY_TIMER_SHAKE_HAND);
    shakeHandMsg.set_version(1);
    std::string ss;
    shakeHandMsg.SerializeToString(&ss);
    zmq_send_wrapper(remote, ss);
}

void LYSimpleTimerMgr::iterateAllTimers()
{
	time_t now = time(NULL);
	std::map<std::string, LYTimerPtr>::iterator it = timers.begin();
	std::vector<std::string> fired_timers;
	for (; it!= timers.end(); it++) {
//		std::cout << "inspecting " << it->first << std::endl;
		LYTimerPtr timer = it->second;
		if (timer->go_fire(now)) {
			//目前不支持repated timers, 所以go fired 就删除
			fired_timers.push_back(it->first);
			onTimeout(it->first);
		}
	}
	std::vector<std::string>::iterator it2 = fired_timers.begin();
	for (; it2!= fired_timers.end(); it2++) {
		it = timers.find(*it2);
		if (it != timers.end()) {
			timers.erase(it);
		}
	}

}

LYSimpleTimerMgr::~LYSimpleTimerMgr()
{
    // TODO Auto-generated destructor stub
}

void LYSimpleTimerMgr::zmq_sendmore_wrapper(zmq::socket_t &z, const string &msg) //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
{
	s_sendmore(z, msg);
}

void LYSimpleTimerMgr::zmq_send_wrapper(zmq::socket_t &z, const string &msg) //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
{
	s_send(z, msg);
}

void LYSimpleTimerMgr::buildTimerMsg(LYTimerPtr t, enum LYTimerAction cmd, std::string& msg)
{
	com::luyun::timer::shared::LYTimerMsg tmsg;
	tmsg.set_version(1);
	if (t->get_server_timer_id() != "" &&
			(cmd == LY_TIMER_CAN || cmd == LY_TIMER_RESET)) {
		tmsg.set_server_timer_id(t->get_server_timer_id());
	}
	tmsg.set_client_timer_id(t->get_client_timer_id());
	tmsg.set_second_client_timer_id(t->get_second_client_timer_id());
	tmsg.set_after(t->get_after());
	tmsg.set_repeat(0.0);
	tmsg.set_client_reserved1(t->get_client_reserved1());
	tmsg.set_client_reserved2(t->get_client_reserved2());
	bool send_reg = false;
	do {
		send_reg = false;
		tmsg.set_action(cmd);
		if (LY_TIMER_RESET == cmd) { //先发一次Cancel，然后发一次Register
			tmsg.set_action(LY_TIMER_CAN);
			cmd = LY_TIMER_REG;
			send_reg = true;
		}
		LY_LOG_DBG("message to timerd: \n" << tmsg.DebugString());
		tmsg.SerializeToString(&msg);
	} while (cmd == LY_TIMER_RESET || send_reg == true);
}

