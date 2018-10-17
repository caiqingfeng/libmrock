/*
 * ServerDispatcher.h
 *
 *  Created on: 2013-8-23
 *      Author: chenfeng
 */

#ifndef SERVERDISPATCHER_H_
#define SERVERDISPATCHER_H_

#define TIME_OUT 60000

#include "ServerHandler.h"
#include "JsonHandler.h"

namespace com {
namespace luyun {
namespace handler {
namespace server {

class Timer {
private:
//    zmq::socket_t& socket;

public:
    Timer();
    virtual ~Timer();
    void run();
};

class ServerDispatcher {
private:
    static ServerDispatcher* _instance;
    Timer *timer;
    ServerHandler *handler; //用于处理Netd发过来的消息
    JsonHandler* jsonHandler; //用于处理Json Port发过来的消息
    ServerDispatcher();

public:
    static ServerDispatcher* Instance();
    virtual ~ServerDispatcher();
    void dispatch();
};

} /* namespace server */
} /* namespace handler */
} /* namespace luyun */
} /* namespace com */
#endif /* SERVERDISPATCHER_H_ */
