/*
 * SessionM.cpp
 *
 *  Created on: 2013-3-6
 *      Author: tommy
 */
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "SessionM.h"
#include "common/src/alg.h"
#include "NetdPersistenceService.h"
#include <boost/algorithm/string.hpp>
#include "common/src/LYUtils.h"

using namespace std;
using namespace com::luyun::msg;
using namespace CryptoPP;

namespace com {
namespace luyun {
namespace msg {

SessionM::~SessionM() {
	// TODO Auto-generated destructor stub
}

void SessionM::cleanDuplicateZmq(const std::string& zmq_id, const std::string& uid)
{
	std::map<std::string, std::string>::iterator it = zmq_fast_index.find(zmq_id);
	if (it != zmq_fast_index.end() && (*it).second != uid) {
		sessions.erase((*it).second);
	}
	zmq_fast_index[zmq_id] = uid;
}

void SessionM::updateSession(OtaMsg& msg, const string& zmq_id) {
//    Session session;
	std::map<std::string, SessionPtr>::iterator it = sessions.find(msg.uid());
	if (it == sessions.end()) {
		LY_LOG_DBG("new user, no session, need create:" << msg.uid());

		// create session
		SessionPtr session(new Session(msg.uid(), zmq_id));
		std::pair<std::string, SessionPtr> value(msg.uid(), session);
		sessions.insert(value);
		cleanDuplicateZmq(zmq_id, msg.uid());
		return;
	}
	LY_LOG_DBG("not new:" << msg.uid());
	// create session or reuse
//	assert(this->haveSession(msg.uid()));
	std::string origin_zid = (*it).second->updateZmqId(zmq_id);
	if(origin_zid != ""){
		sendKickOff(origin_zid, msg.uid());
	}
	(*it).second->recv_pkg_num++;
	//20141203防止两个不同客户端登录同一个终端时，服务器把两个用户的信息都发往该终端
	cleanDuplicateZmq(zmq_id, msg.uid());
}
void SessionM::sendKickOff(std::string origin_zid, std::string uid){
	s_sendmore(wan_socket, origin_zid);
	s_send(wan_socket, std::string("{\"info\":\"kick off\"")+std::string(",\"uid\":\"")+uid+std::string("\"}"));
}
bool SessionM::isValid(string& msg, string& digest, OtaMsg& otaMsg) {
	string key = getKey(otaMsg.uid());
	if (key == "") {
		LY_LOG_ERR("no key");
		return false;
	}
	LY_LOG_DBG("key=" << key);

//	string mac, hexMac;
//
//	try {
//		HMAC<MD5> hmac((byte*) key.data(), key.size());
//
//		//get msg mac
//		StringSource(msg, true, new HashFilter(hmac, new StringSink(mac)));
//	} catch (const CryptoPP::Exception& e) {
//		LY_LOG_ERR(e.what());
//		return false;
//	}
//
//	hexMac.clear();
//	StringSource(mac, true, new HexEncoder(new StringSink(hexMac)));
	std::string hexMac;
	LYUtils::genDigest(msg, key, hexMac);

	string upper_hmac = digest;
	boost::to_upper(upper_hmac);

	LY_LOG_DBG("hexMac=" << hexMac << ",,,,,digest=" << upper_hmac);
	if (hexMac != upper_hmac) {
		LY_LOG_ERR("mac error");
		return false;
	}

	//other message check time stamp
	if (this->haveSession(otaMsg.uid())) {
		if (false == sessions[otaMsg.uid()]->checkTs(otaMsg.time_stamp())) {
			LY_LOG_DBG("time_stamp replay");
//            return false;
		}
	}

	return true;
}

string SessionM::getKey(const string& uid) {
	if (this->haveSession(uid) && sessions[uid]->haveKey()) {
		return sessions[uid]->getKey();
	}
//	std::cout << "uid=" << uid <<std::endl;

	string key = NetdPersistenceService::Instance()->getKey(uid);

    if (this->haveSession(uid)) {
        sessions[uid]->updateKey(key);
    }
//	std::cout << "key=" << key <<std::endl;
    return key;
}

void SessionM::onWanMsg(string& zmq_id, string& msg, string& payload,
		string& digest) {
	OtaMsg otaMsg;
	if (!otaMsg.ParseFromString(msg)) {
		LY_LOG_ERR("decode msg fail: ");
		return;
	}

	LY_LOG_DBG("otaMsg:\n" << otaMsg.DebugString());

	if (false == isValid(payload, digest, otaMsg)) {
		LY_LOG_ERR("invalid msg!");
		return;
	}

	std::string pre_confirmed_service = "";
	if (otaMsg.has_server_handler()) pre_confirmed_service = otaMsg.server_handler();
	forwardMsg(msg, payload, pre_confirmed_service);
	updateSession(otaMsg, zmq_id);
}

void SessionM::forwardMsg(string& msg, string& payload, const std::string pre_confirmed_service) {
	std::string service_addr = this->dispatcher(pre_confirmed_service);
	s_sendmore(lan_socket, service_addr);
	s_sendmore(lan_socket, msg);
	s_send(lan_socket, payload);
}

void SessionM::forwardJson(string& msg)
{
//	s_send(json_socket, msg);
}

void SessionM::bcastMsg(zmq::socket_t& socket, string& msg) {
	std::pair<string, SessionPtr> pr;
	BOOST_FOREACH(pr, sessions) {
		s_sendmore(socket, pr.second->getConnId());
		s_send(socket, msg);
	}
}

void SessionM::mcastMsg(zmq::socket_t& socket, string uids, string& msg) {
	OtaMulticast uid_list;

	try {
		bool rt = uid_list.ParseFromString(uids);
		if (rt != true) {
			return;
		}
	} catch (std::exception & e) {
		LY_LOG_ERR("ParseFromString " << e.what());
		return;
	}

	for (int i = 0; i < uid_list.uid_size(); i++) {
		if (this->haveSession(uid_list.uid(i))) {
			string conn_id = sessions[uid_list.uid(i)]->getConnId();
			if (conn_id != "") {
				LY_LOG_INF("send to: "<< uid_list.uid(i));
				s_sendmore(socket, conn_id);
				s_send(socket, msg);
			}
		} else {
			LY_LOG_ERR("unfound session for uid: " << uid_list.uid(i));
		}
	}
}

bool SessionM::haveSession(const string& uid) {
	return sessions.find(uid) != sessions.end();
}

void SessionM::onJsonCall(string& msg)
{

}

void SessionM::register_service(const std::string& addr)
{
	std::vector<std::string>::iterator it = service_addrs.begin();
	for (; it!=service_addrs.end(); it++) {
		if ((*it) == addr) {
			return;
		}
	}
	service_addrs.push_back(addr);
}

/*
 * 20150127增加，可处理load_balance (以后增加）
 * 或者大波罗里的两个不同的Server
 */
std::string SessionM::dispatcher(const std::string& pre_confirmed_service)
{
	int service_size = service_addrs.size();
	if (service_size == 0) return "";
	if (service_size == 1) return service_addrs[0];

	if (pre_confirmed_service != "") return pre_confirmed_service;

	return service_addrs[0];
}


}
}
}
