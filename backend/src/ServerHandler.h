/*
 * ServerHandler.h
 *
 *  Created on: 2013-8-23
 *      Author: chenfeng
 */

#ifndef SERVERHANDLER_H_
#define SERVERHANDLER_H_

#include "common/src/MsgHandler.h"
#include "ServerHandlerImpl.h"

using namespace std;
using namespace com::luyun::msg;

namespace com {
namespace luyun {
namespace handler {
namespace server {

extern PersistenceService *g_persistenceService;

class ServerHandler: public com::luyun::msg::MsgHandler {
private:
	ServerHandlerImpl *handlerImpl;

public:
	ServerHandler(zmq::socket_t& socket, ServerHandlerImpl *impl);
	virtual ~ServerHandler();
	void onMsg(string& msg);
	void onJsonCall(string& msg);
	void onPayload(string& payload, std::string& uid);
	void getUpdateState();
	void getSystemMsg();
	ServerHandlerImpl* getHandlerImp() {return handlerImpl;};

	void pushNotificationToMobile(const std::string& uid, const std::string& msg);

public:
	void onTimeout(std::string& msg);
};

} /* namespace server */
} /* namespace handler */
} /* namespace luyun */
} /* namespace com */

#endif /* SERVERHANDLER_H_ */
