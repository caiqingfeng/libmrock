/*
 * JsonHandler.h
 *
 *  Created on: 2014-11-05
 *      Author: chenfeng
 *      本类用于专门处理Json端口消息和命令，用于与Rails通信
 */

#ifndef JSONHANDLER_H_
#define JSONHANDLER_H_

#include "common/src/MsgHandler.h"

class JsonHandler: public com::luyun::msg::MsgHandler {
public:
	JsonHandler(zmq::socket_t& socket);
	virtual ~JsonHandler();

public:
	virtual void onJsonCall(const std::string& zid, const std::string& msg) = 0;
	virtual void replyJson(const std::string& zid, const std::string& jsonStr);
};

#endif
