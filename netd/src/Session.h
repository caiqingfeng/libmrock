/*
 * Session.h
 *
 *  Created on: 2013-3-6
 *      Author: tommy
 */

#ifndef SESSION_H_
#define SESSION_H_

#include <string>
#include <boost/utility.hpp>
#include "common/src/my_log.h"
#include <boost/shared_ptr.hpp>
#include "common/src/LYUtils.h"

using std::string;

namespace com {
namespace luyun {
namespace msg {

//extern const int keep_alive_time;
//extern PersistenceService *g_persistenceService;

/* 用户在webserver 完成登陆过程，客户端取到 access token
 * 在checkin 消息中携带 digest 和用户 uid
 * server 接收到 checkin, 校验通过
 * 创建一个与用户对应的 session
 */
class Session {
private:
	// TODO 是否支持同一用户同时登陆多台设备
	string uid; // user id
	string zmq_id; //连接标示,zmq_id，是由zmq随机分配的，同一个客户端重新连接后会发生变化
	string key; // hmac 校验使用
	long long ts; // timestamp最后收到的客户端消息时间戳, 用于防止 replay 攻击

public:
	bool status; //表明是否alive
	int recv_pkg_num;

public:
	Session(const string& id, const string& zmq);

	virtual ~Session();
	void save();

	inline string& getKey() {
		return key;
	}

	void updateKey(const string& k) {
		this->key = k;
	}

	bool haveKey() {
		return key != "";
	}
	// update time_stamp, if the new ts <= time_stamp, it's a invalid ,return fasle;
	bool checkTs(long long ts) {
		if (ts < this->ts) {
			LY_LOG_DBG("this ts: "<< this->ts << " msg ts: " << ts);
			return false;
		}
		this->ts = ts;
		return true;
	}
//
	inline string updateZmqId(const string& zmq) {
		LYUtils::printTextOrBinary(std::string("now zmqid: "), zmq);
		LYUtils::printTextOrBinary(std::string("origin zmqid: "), this->zmq_id);
		string origin_zid = "";
		if (zmq != this->zmq_id) {
			origin_zid = this->zmq_id;
			this->zmq_id = zmq;
			this->status = true;
//			save();
		}
		return origin_zid;
	}

	inline string getConnId() {
		return zmq_id;
	}

	void registerTimer(const float after);
	void cancelCurrentTimer();
};

}
}
}

#endif /* SESSION_H_ */
