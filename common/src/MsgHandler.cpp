//
//  MsgHandler.cpp
//  ibuddyholdem
//
//  Created by chenfeng on 13-7-6.
//  Copyright (c) 2013年 chenfeng. All rights reserved.
//

#include "MsgHandler.h"
#include "common/src/alg.h"
#include "common/src/LYUtils.h"

namespace com {
namespace luyun {
namespace msg {

MsgHandler::MsgHandler(zmq::socket_t& socket, const string& uid, const string& key):
        _socket(socket), _uid(uid), _key(key)
{
    // TODO Auto-generated constructor stub
}

MsgHandler::~MsgHandler() {
    // TODO Auto-generated destructor stub
}

void MsgHandler::quit()
{
    string cmd = "QT";
    sendMsg(cmd);
}

void MsgHandler::reconnect(std::string& connect_to)
{
    string cmd = "RC";
    sendMsg(cmd, true);
    sendMsg(connect_to, false);
}

void MsgHandler::setUidAndKey(std::string& uid, std::string& key, bool forward)
{
    if (forward) {
        string cmd = "UK";
        sendMsg(cmd, true);
        sendMsg(uid, true);
        sendMsg(key, false);
    } else {
	    _uid = uid;
    	_key = key;
    }
}
void MsgHandler::shakeHands()
{
	std::string m = "SK";
	sendMsg(m);
}

/*
 * to server, 后续跟着payload，因此用s_sendmore
 * 20150127修改，增加server_handler参数，用于指定送到哪个服务器来处理
 */
void MsgHandler::sendMsg(OtaMsg& msg, const std::string server_handler)
{
	std::string m = "m";
    sendMsg(m, true);
    std::string strMsg;
    buildMsg(msg, server_handler);
    msg.SerializeToString(&strMsg);
    sendMsg(strMsg, true);
}

/*
 * 这个方法只是调用zmq方法，被服务器和客户都调用，由它们设定是否需要发送pioneer_msg
 */
void MsgHandler::sendMsg(string& msg, bool hasMore)
{
    if (hasMore) {
//        s_sendmore(_socket, msg);
        zmq_sendmore_wrapper(_socket, msg);
    } else {
//        s_send(_socket, msg);
        zmq_send_wrapper(_socket, msg);
    }
}

//void MsgHandler::sendCryptoMsg(OtaMsg& msg)
//{
//    std::string strMsg;
//    buildMsg(msg);
//    msg.SerializeToString(&strMsg);
//    sendCryptoMsg(strMsg);
//}

void MsgHandler::sendCryptoMsg(string& msg)
{
	zmq_sendmore_wrapper(_socket, "p");
    //s_sendmore(_socket, msg);
	zmq_sendmore_wrapper(_socket, msg);
	zmq_sendmore_wrapper(_socket, "d");

    //digest
//    string mac, hexMac;
//    CryptoPP::HMAC<CryptoPP::MD5> hmac((byte*) _key.data(), _key.size());
//
//    //get msg mac
//    CryptoPP::StringSource(msg, true, new CryptoPP::HashFilter(hmac, new CryptoPP::StringSink(mac)));
//    CryptoPP::StringSource(mac, true, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hexMac)));
//    s_send(_socket, hexMac);
	std::string hexMac;
	LYUtils::genDigest(msg, _key, hexMac);
    zmq_send_wrapper(_socket, hexMac);
}

void MsgHandler::buildMsg(OtaMsg& msg, const std::string server_handler)
{
    try {
        msg.set_msg_id(0);
        msg.set_time_stamp(time(NULL));
        msg.set_version(1);
        msg.set_uid(_uid);
        msg.set_server_handler(server_handler);
//        msg.set_debug_info(_key);
    } catch (std::exception& e) {
        LY_LOG_ERR(e.what());
    }
}

void MsgHandler::zmq_sendmore_wrapper(zmq::socket_t &z, const string &msg) //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
{
	s_sendmore(z, msg);
}

void MsgHandler::zmq_send_wrapper(zmq::socket_t &z, const string &msg) //为了增加可测性，在测试函数中重载此方法即可实现不连ZMQ也能单元测试的目的
{
	s_send(z, msg);
}

} /* namespace msg */
} /* namespace luyun */
} /* namespace com */
