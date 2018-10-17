/*
 * Session.cpp
 *
 *  Created on: 2013-3-6
 *      Author: tommy
 */

#include "Session.h"
#include "NetdPersistenceService.h"

namespace com {
namespace luyun {
namespace msg {

//const int keep_alive_time = 60 * 30;
//PersistenceService *g_persistenceService;

Session::Session(const string& id, const string& zmq) :
		ts(0), uid(id), key(""), zmq_id(zmq), status(true), recv_pkg_num(1) {
    key = NetdPersistenceService::Instance()->getKey(uid);
//	save();
}

Session::~Session() {
	// TODO Auto-generated destructor stub
}

//void Session::save() {

//}

}
}
}
