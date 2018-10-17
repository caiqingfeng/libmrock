/*
 * LYTimerManager.cpp
 *
 *  Created on: 2013-5-3
 *      Author: caiqingfeng
 */

#include "../../concrete/src/LYTimerManager.h"

#include <ev.h>
#include <boost/shared_ptr.hpp>
#include "common/src/timer.pb.h"
#include <exception>

ev_io zmq_watcher;
ev_io inproc_watcher;
extern LYTimerManagerPtr timerMgr;

using namespace com::luyun::timer::shared;
using namespace com::luyun::timer;

static void io_cb(EV_P_ ev_io *watcher, int ev_events)
{
    if (EV_ERROR & ev_events)
    {
        puts("invalid event");
        return;
    }

    timerMgr->handleNW();

}

static void timeout_cb(EV_P_ ev_timer *watcher, int ev_events)
{
    if (EV_ERROR & ev_events)
    {
        puts("invalid event");
        return;
    }

    std::ostringstream ios;
    ios << static_cast<void *> (watcher);
    timerMgr->onTimeout(ios.str());

}

LYTimerManager::LYTimerManager(zmq::socket_t& rm) :
        remote(rm)
{
}

void LYTimerManager::handleNW()
{
    unsigned int zmq_events;
    size_t opt_len;

    try
    {
        while (1)
        {
            this->remote.getsockopt(ZMQ_EVENTS, &zmq_events, &opt_len);

            if (ZMQ_POLLIN & zmq_events)
            {
                std::string client = s_recv(this->remote); //get address
                std::string msg = s_recv(this->remote); //get real message then
                this->onMsg(client, msg);
            }
            else
            {
                break;
            }
        }
    } catch (std::exception &e)
    {
//		LY_LOG_ERR("fatal error happened, zmq failed!");
        return;
    }
}

void LYTimerManager::onMsg(const string &from, const string &msg)
{
    //decode msg
    LYTimerMsg timerMsg;
    std::string replyTo = from;

    if (!timerMsg.ParseFromString(msg))
    {
        LY_LOG_ERR("fatal error, decode failed");
        return;
    }
    LY_LOG_DBG("get timer registered\n" << timerMsg.DebugString());
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
    boost::shared_ptr<ev_timer> ev_timer_ptr = timerPtr->getTimeout();
    switch (timerMsg.action())
    {
    case LY_TIMER_REG:
        ev_timer_init(ev_timer_ptr.get(), timeout_cb, after, repeat);
        ev_timer_start(loop, ev_timer_ptr.get());
        break;
    case LY_TIMER_CAN:
        ev_timer_stop(loop, ev_timer_ptr.get());
        timers.erase(it);
        return; //cancel timer doesn't send message back
    case LY_TIMER_RESET: //20130814目前不支持
        ev_timer_stop(loop, ev_timer_ptr.get());
        ev_timer_start(loop, ev_timer_ptr.get());
        break;
    case LY_TIMER_FIRE:
    default:
        LY_LOG_ERR("wrong msg" << timerMsg.DebugString());
        return;
    }
    s_sendmore(remote, replyTo);
    std::string ss;
    replyMsg.set_action(LY_TIMER_CONF);
    replyMsg.SerializeToString(&ss);
    s_send(remote, ss);
    LY_LOG_DBG("confirmed message \n" << replyMsg.DebugString());
}

void LYTimerManager::onTimeout(const string &timerId)
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
    s_sendmore(remote, tp->getClient());
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
    s_send(remote, ss);
    //delete timer to release memory
    if (tp->get_repeat() == 0.0 
    		|| (tp->get_repeat() > 0.0 && time(NULL) > tp->get_will_stop_at())){
    	if (tp->get_repeat() > 0.0) {
    		ev_timer_stop(loop, tp->getTimeout().get());
    	}
        timers.erase(it);
    } 
}

void LYTimerManager::run()
{
    loop = ev_default_loop(0);

    size_t opt_len;
    int zmq_fd = 0;
    try
    {
        remote.getsockopt(ZMQ_FD, &zmq_fd, &opt_len);
    } catch (std::exception& e)
    {
        LY_LOG_ERR(e.what());
    }

    // initialise an io watcher, then start it
    // this one will watch for stdin to become readable
    ev_io_init(&zmq_watcher, io_cb, zmq_fd, EV_READ);
    ev_io_start(loop, &zmq_watcher);

//    int inproc_fd = 0;
//    size_t inproc_opt;
//    inproc.getsockopt(ZMQ_FD, &inproc_fd, &inproc_opt);
//    ev_io_init (&inproc_watcher, inproc_cb, inproc_fd, EV_READ);
//    ev_io_start (loop, &inproc_watcher);

    // now wait for events to arrive
    ev_run(loop, 0);

    // break was called, so exit
//    return 0;
}

LYTimerManager::~LYTimerManager()
{
    // TODO Auto-generated destructor stub
}

