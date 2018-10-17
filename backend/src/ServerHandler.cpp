/*
 * ServerHandler.cpp
 *
 *  Created on: 2013-8-23
 *      Author: chenfeng
 */

#include "ServerHandler.h"

#include "common/src/OtaSerializeHelper.h"
#include "common/src/timer.pb.h"

using namespace com::luyun::msg;

namespace com {
namespace luyun {
namespace handler {
namespace server {

PersistenceService *g_persistenceService;

ServerHandler::ServerHandler(zmq::socket_t& socket, ServerHandlerImpl *impl) :
		        MsgHandler(socket) {
    // TODO Auto-generated constructor stub
	handlerImpl = impl;
}

ServerHandler::~ServerHandler() {
    // TODO Auto-generated destructor stub
}

void ServerHandler::onMsg(string& msg) {
    OtaMsg otaMsg;
    try {
        if (!otaMsg.ParseFromString(msg)) {
            LY_LOG_ERR("ParseFromString fail");
            return;
        }

        LY_LOG_DBG("otaMsg:\n" << otaMsg.DebugString());
        _uid = otaMsg.uid();

    } catch (std::exception& e) {
        LY_LOG_ERR("onMsg exception" << e.what());
    }
}

void ServerHandler::onPayload(string& msg, std::string& uid) {
	if (handlerImpl == NULL) {
		LY_LOG_ERR("fatal error: no implementation installed for handler!");
		return;
	}
	handlerImpl->onPayload(msg, uid);
}

//20150128 增加，需要增加处理
void ServerHandler::onTimeout(std::string& msg)
{
	com::luyun::timer::shared::LYTimerMsg tmsg;
	try {
		tmsg.ParseFromString(msg);
		LYTimer timer = OtaSerializeHelper::ota2timer(tmsg);
		//LY_LOG_DBG("message from timerd: " << tmsg.DebugString());
		if (timer.get_action() == com::luyun::timer::shared::LY_TIMER_SHAKE_HAND) {
			handlerImpl->onShakeHandTimer();
			return;
		}
		handlerImpl->onTimeout(timer);
	} catch (std::exception &e){
		LY_LOG_ERR("exception!" << e.what());
		return;
	}
}

void ServerHandler::pushNotificationToMobile(const std::string& uid, const std::string& msg)
{
	if (handlerImpl == NULL) {
		LY_LOG_ERR("fatal error: no implementation installed for handler!");
		return;
	}
	handlerImpl->pushNotificationToMobile(uid, msg);
}

} /* namespace server */
} /* namespace handler */
} /* namespace luyun */
} /* namespace com */
