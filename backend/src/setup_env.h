/*
 * setup_env.h
 * 只能被Main Include，如appdmain.cpp, test/main.cpp
 *
 *  Created on: 2014-4-10
 *      Author: caiqingfeng
 */

#ifndef SETUP_ENV_H_
#define SETUP_ENV_H_

#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"
#include "persistence/src/PersistenceServiceDelegate.h"
#include "persistence/src/PersistenceServiceRedis.h"
#include "ServerHandler.h"
#include "JsonHandler.h"

zmq::context_t context(1);
//zmq::socket_t g_socketLocalSvr(context, ZMQ_PAIR);
//zmq::socket_t g_socketLocalClt(context, ZMQ_PAIR);
zmq::socket_t g_socketRemote(context, ZMQ_DEALER);
zmq::socket_t g_socketTimer(context, ZMQ_DEALER);
zmq::socket_t g_socketJson(context, ZMQ_ROUTER); /*Rails作为Dealer，服务器作为Router*/
com::luyun::handler::server::ServerHandler *g_serverHandler; /*处理Netd过来的消息 */
JsonHandler* g_jsonHandler; /*处理Http过来的消息 */

log4cplus::Logger logger;

void setupZmq(const std::string server_handler="APPD")
{
    char *server_base = getenv("LUYUN_SERVER_BASE");
    std::string lan_port = "9002";
    std::string json_port = "9004";
    if (server_base != NULL) {
    	int base_port = atoi(server_base);
    	char buf[20];
    	memset(buf, 0, 20);
    	sprintf(buf, "%d", base_port + 2);
    	lan_port = buf;
        memset(buf, 0, 20);
        sprintf(buf, "%d", base_port + 4);
        json_port = buf;
    }
    g_socketRemote.setsockopt(ZMQ_IDENTITY, server_handler.c_str(), server_handler.size());
    std::string lan_server = "tcp://127.0.0.1:"+lan_port;
    g_socketRemote.connect(lan_server.c_str());
    std::string timer_server = "ipc:///tmp/"+server_handler;
    g_socketTimer.connect(timer_server.c_str());
    std::string json_server = "tcp://127.0.0.1:"+json_port;
    g_socketJson.bind(json_server.c_str());

//    g_socketLocalSvr.bind("inproc://com.luyun.timer");
}

#endif
