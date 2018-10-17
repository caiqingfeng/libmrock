/*
 * ServerHandler.h
 *
 *  Created on: 2014-4-10
 *      Author: caiqingfeng
 */

#ifndef SERVERHANDLER_IMPL_H_
#define SERVERHANDLER_IMPL_H_

#include "persistence/src/PersistenceService.h"
#include "common/src/MsgHandler.h"
#include "common/src/LYTimer.h"

using namespace std;
using namespace com::luyun::msg;

namespace com {
namespace luyun {
namespace handler {
namespace server {

class ServerHandlerImpl: public com::luyun::msg::MsgHandler {
public:
	ServerHandlerImpl(zmq::socket_t& socket);
	virtual ~ServerHandlerImpl();
	virtual void onMsg(string& msg);
	virtual void onPayload(string& payload, std::string& uid) = 0;
	virtual void pushNotificationToMobile(const std::string& uid, const std::string& msg) = 0;
	virtual void onTimeout(LYTimer& t) {};
	virtual void onShakeHandTimer() {};
};

} /* namespace server */
} /* namespace handler */
} /* namespace luyun */
} /* namespace com */

#endif /* SERVERHANDLER_IMPL_H_ */
