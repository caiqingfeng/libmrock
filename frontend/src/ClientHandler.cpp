/*
 * ClientHandler.cpp
 *
 *  Created on: 2013-8-26
 *      Author: chenfeng
 */

#include "ClientHandler.h"

namespace com {
namespace luyun {
namespace msg {
namespace client {

ClientHandler::ClientHandler(zmq::socket_t& socket, com::luyun::msg::client::ClientHandlerImpl* handler,
		const std::string& uid, const std::string& key) :
		MsgHandler(socket, uid, key) {
	// TODO Auto-generated constructor stub
	handlerImpl = handler;
}

ClientHandler::~ClientHandler() {
	// TODO Auto-generated destructor stub
	delete handlerImpl;
}

void ClientHandler::setUidAndKey(std::string& uid, std::string& key, bool forward)
{
	com::luyun::msg::MsgHandler::setUidAndKey(uid, key, forward);

	if (handlerImpl == NULL || forward) return;
	handlerImpl->setUidAndKey(uid, key, false);;
}

void ClientHandler::setCallback(Callback* cb)
{
	if (handlerImpl == NULL) {
		return;
	}
	handlerImpl->setCallback(cb);
}

void ClientHandler::onPayload(string& msg) {
	if (handlerImpl == NULL) {
		LY_LOG_ERR("fatal error! no handler implemented!");
		return;
	}
	handlerImpl->onPayload(msg);
}

} /* namespace client */
} /* namespace msg */
} /* namespace luyun */
} /* namespace com */
