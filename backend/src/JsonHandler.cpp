#include "JsonHandler.h"

JsonHandler::JsonHandler(zmq::socket_t& socket) :
		        MsgHandler(socket) {
    // TODO Auto-generated constructor stub
}

JsonHandler::~JsonHandler() {
    // TODO Auto-generated destructor stub
}

void JsonHandler::replyJson(const std::string& zid, const std::string& msg)
{
	zmq_sendmore_wrapper(_socket, zid);
	zmq_send_wrapper(_socket, msg);
}
