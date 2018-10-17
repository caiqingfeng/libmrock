#include "ClientHandlerImpl.h"

namespace com {
namespace luyun {
namespace msg {
namespace client {

ClientHandlerImpl::ClientHandlerImpl(zmq::socket_t& socket) : MsgHandler(socket)
{
}

ClientHandlerImpl::~ClientHandlerImpl()
{
}

void ClientHandlerImpl::setCallback(Callback* cb)
{
	_callback = cb;
}

} /* namespace client */
} /* namespace msg */
} /* namespace luyun */
} /* namespace com */


