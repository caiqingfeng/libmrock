/*
 * MessageStubs.h
 *
 *  Created on: 2013-7-10
 *      Author: caiqingfeng
 */

#ifndef MESSAGESTUBS_H_
#define MESSAGESTUBS_H_

#include "common/src/zhelpers.hpp"
#include "concrete/src/LYSimpleTimerMgr.h"

//avoid sending data via zmq
//for the sake of unit testing
//class MockMsgHandler : public AppdHandlerImpl
//20150207修改，继承自ＫingHandlerImpl
class MockMsgHandler : public LYSimpleTimerMgr
{
public:
//	MockMsgHandler(zmq::socket_t &peer) : AppdHandlerImpl(peer) {};
	MockMsgHandler(zmq::socket_t &peer) : LYSimpleTimerMgr(peer) {};
	virtual void zmq_sendmore_wrapper(zmq::socket_t &z, const string &msg); //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
	virtual void zmq_send_wrapper(zmq::socket_t &z, const string &msg); //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
};

#endif


