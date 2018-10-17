/*
 * ServerDispatcher.cpp
 *
 *  Created on: 2013-8-23
 *      Author: chenfeng
 */

#include "ServerDispatcher.h"
#include <boost/thread.hpp>
#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"
#include "JsonHandler.h"

using namespace std;

extern zmq::context_t context;
//extern zmq::socket_t g_socketLocalSvr;
//extern zmq::socket_t g_socketLocalClt;
extern zmq::socket_t g_socketRemote;
extern zmq::socket_t g_socketTimer;
extern zmq::socket_t g_socketJson;
extern com::luyun::handler::server::ServerHandler *g_serverHandler;
extern JsonHandler* g_jsonHandler;

namespace com {
namespace luyun {
namespace handler {
namespace server {

ServerDispatcher* ServerDispatcher::_instance = NULL;

ServerDispatcher* ServerDispatcher::Instance()
{
    if(_instance == 0)
    {
        _instance = new ServerDispatcher();
    }
    return _instance;
}

ServerDispatcher::ServerDispatcher() {
    // TODO Auto-generated constructor stub
    LY_LOG_DBG("Constructing ServerDispatcher...");
//    sleep(1);
//    timer = new Timer();
    handler = g_serverHandler;
    jsonHandler = g_jsonHandler;
//    new boost::thread(&Timer::run, timer);
}

ServerDispatcher::~ServerDispatcher() {
    // TODO Auto-generated destructor stub
    delete timer;
    timer = NULL;
    delete handler;
    handler = NULL;
}

void ServerDispatcher::dispatch()
{
    zmq::pollitem_t items[] =
    {
            { g_socketRemote, 0, ZMQ_POLLIN, 0 },
//            { g_socketLocalSvr, 0, ZMQ_POLLIN, 0 },
            { g_socketTimer, 0, ZMQ_POLLIN, 0 },
            { g_socketJson, 0, ZMQ_POLLIN, 0 }
    };

    s_send(g_socketRemote, "ready");
    //added 20151231, zmq服务器必须要收到客户端的消息先，才能发包回来
    s_send(g_socketTimer, "ready");
    s_send(g_socketJson, "ready");
    //loop for waiting connection from tracker_client
    while (true)
    {
        zmq::poll(&items[0], 3, -1);

        if (items[0].revents & ZMQ_POLLIN)
        {
            string msg = s_recv(g_socketRemote);
            string uid;
            //from handler->onMsg(msg);
            OtaMsg otaMsg;
            try {
                if (!otaMsg.ParseFromString(msg)) {
                    LY_LOG_ERR("ParseFromString fail");
                    return;
                }
                LY_LOG_DBG("otaMsg:\n" << otaMsg.DebugString());
                uid = otaMsg.uid();
            } catch (std::exception& e) {
                LY_LOG_ERR("onMsg exception" << e.what());
            }
            string payload = s_recv(g_socketRemote);
            handler->onPayload(payload, uid);
        }
        // 定时通知
        if (items[1].revents & ZMQ_POLLIN)
        {
            string msg = s_recv(g_socketTimer);
            handler->onTimeout(msg);
        }
        // 定时通知
        if (items[2].revents & ZMQ_POLLIN)
        {
        	std::string zid = s_recv(g_socketJson);
            string msg = s_recv(g_socketJson);
            jsonHandler->onJsonCall(zid, msg);
        }
    }
}

} /* namespace server */
} /* namespace handler */
} /* namespace luyun */
} /* namespace com */
