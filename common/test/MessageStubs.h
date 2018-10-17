/*
 * MessageStubs.h
 *
 *  Created on: 2013-7-10
 *      Author: caiqingfeng
 */

#ifndef MESSAGESTUBS_H_
#define MESSAGESTUBS_H_

#include "common/src/zhelpers.hpp"
#include "common/src/MsgHandler.h"

//avoid sending data via zmq
//for the sake of unit testing
class MockMsgHandler : public com::luyun::msg::MsgHandler
{
public:
	MockMsgHandler(zmq::socket_t &peer) : MsgHandler(peer) {};
	virtual void zmq_sendmore_wrapper(zmq::socket_t &z, const string &msg); //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
	virtual void zmq_send_wrapper(zmq::socket_t &z, const string &msg); //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
    virtual void onMsg(string& msg){};
};

#endif


