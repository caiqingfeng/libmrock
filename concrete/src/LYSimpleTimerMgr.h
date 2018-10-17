/*
 * LYTimerManager.h
 *
 *  Created on: 2013-5-3
 *      Author: caiqingfeng
 */

#ifndef LYSIMPLETIMERMANAGER_H_
#define LYSIMPLETIMERMANAGER_H_

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"

#include "common/src/LYTimer.h"

extern zmq::context_t context;

class LYSimpleTimerMgr {

public:
	LYSimpleTimerMgr(zmq::socket_t &rm);
	virtual ~LYSimpleTimerMgr();
	void run();
	void handleNW();
	void onMsg(const std::string &from, const std::string &msg);
	void onTimeout(const std::string &timerId);
	void iterateAllTimers();
	void shakeHand();
	void buildTimerMsg(LYTimerPtr t, enum LYTimerAction cmd, std::string& msg);

public:
	std::map<std::string, LYTimerPtr> timers;
	struct ev_loop *loop;

public:
	zmq::socket_t& remote; //n/w socket
	virtual void zmq_sendmore_wrapper(zmq::socket_t &z, const string &msg); //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
	virtual void zmq_send_wrapper(zmq::socket_t &z, const string &msg); //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的

};

typedef boost::shared_ptr<LYSimpleTimerMgr> LYSimpleTimerMgrPtr;

#endif /* LYTIMERMANAGER_H_ */
