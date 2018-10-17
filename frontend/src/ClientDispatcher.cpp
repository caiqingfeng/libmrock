//
//  ClientDispatcher.cpp
//
//  Created by chenfeng on 13-7-9.
//  Copyright (c) 2013年 chenfeng. All rights reserved.
//

#include "ClientDispatcher.h"

namespace com {
namespace luyun {
namespace msg {
namespace client {

ClientDispatcher* ClientDispatcher::_instance = NULL;

ClientDispatcher::ClientDispatcher(zmq::socket_t& socket_svr,
		zmq::socket_t& socket_view, ClientHandler *msgHandler) :
		_socket_svr(socket_svr), _socket_view(socket_view), _msgHandler(
				msgHandler) {

}

ClientDispatcher::~ClientDispatcher() {
}

ClientDispatcher* ClientDispatcher::Instance(zmq::socket_t& socket_svr,
		zmq::socket_t& socket_view, ClientHandler *msgHandler) {
	if (_instance == NULL) {
		_instance = new ClientDispatcher(socket_svr, socket_view, msgHandler);
	}
	return _instance;
}

void ClientDispatcher::dispatch() {
	zmq::pollitem_t items[] = { { _socket_svr, 0, ZMQ_POLLIN, 0 }, {
			_socket_view, 0, ZMQ_POLLIN, 0 }, };

	time_t last_msg_from_server = 0;
	time_t last_msg_to_server = 0;
	string connect_to;
	while (true) {
		zmq::poll(&items[0], 2, -1);
		if (items[0].revents & ZMQ_POLLIN) {
			last_msg_from_server = time(NULL);
			string payload = s_recv(_socket_svr);
			_msgHandler->onPayload(payload);
		}
		if (items[1].revents & ZMQ_POLLIN) {
			string payload = s_recv(_socket_view);
			string server_handler = "";
			LY_LOG_DBG(
					"got msg from application and sending to server..."
							<< payload);
			if (payload.size() == 2) {
				if (payload == "QT") {
					break;
				} else if (payload == "RC") {
					connect_to = s_recv(_socket_view);
					try {
						_socket_svr.connect(connect_to.c_str());
					} catch (std::exception& e) {
						std::cout << "connect exception: " << e.what();
					}
					continue;
				} else if (payload == "UK") {
					string uid = s_recv(_socket_view);
					string key = s_recv(_socket_view);
					LY_LOG_DBG(
							"ClientDispatcher, uid: " << uid << ", key: "
									<< key);
					_msgHandler->setUidAndKey(uid, key, false);
					continue;
				} else if (payload == "SK") {
					//10s一次心跳
					if (time(NULL) - last_msg_to_server > 10) {
						last_msg_to_server = time(NULL);
						_msgHandler->shakeHands();
					}
					continue;
				} else if (payload == "SR") {
					//20150205新增支持指定服务器处理
					server_handler = s_recv(_socket_view);
					payload = s_recv(_socket_view);
				}
			}

			//20141202增加，如果2分钟之内未收到服务器的任何消息，可能失联
			if (time(NULL) - last_msg_from_server > 120 && connect_to != "") {
				LY_LOG_DBG(
						"automatically reconnect to server..." << connect_to);
				try {
					_socket_svr.connect(connect_to.c_str());
				} catch (std::exception& e) {
					std::cout << "connect exception: " << e.what();
				}
			}
			last_msg_to_server = time(NULL);
			OtaMsg otaMsg;
			/*
			 * 此处可以加上LoadBalance算法，客户端随机选择一个服务器
			 */
			if (server_handler != "") {
				_msgHandler->sendMsg(otaMsg, server_handler);
			} else {
				_msgHandler->sendMsg(otaMsg);
			}
			_msgHandler->sendCryptoMsg(payload);
		}
	}
}

} /* namespace client */
} /* namespace msg */
} /* namespace luyun */
} /* namespace com */
