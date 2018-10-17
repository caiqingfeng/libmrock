#include "ServerHandlerImpl.h"

namespace com {
namespace luyun {
namespace handler {
namespace server {

ServerHandlerImpl::ServerHandlerImpl(zmq::socket_t& socket) : MsgHandler(socket)
{
}

ServerHandlerImpl::~ServerHandlerImpl()
{
}

void ServerHandlerImpl::onMsg(std::string& msg)
{
}


} /* namespace server */
} /* namespace handler */
} /* namespace luyun */
} /* namespace com */


