#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"
#include "LYSimpleTimerMgr.h"


log4cplus::Logger logger;

LYSimpleTimerMgrPtr timerMgr;

zmq::context_t context(1);

zmq::socket_t remoteSocket(context, ZMQ_ROUTER);



int main(int argc, char* argv[]) {
	logger = getLogger(argv[0]);
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <executable>" << std::endl;
		exit(-1);
	}

	std::string ipc_socket = "ipc:///tmp/" + std::string(argv[1]);
//	std::string ipc_socket = "tcp://0.0.0.0:5678";
LY_LOG_DBG("listening ..." << ipc_socket);

    remoteSocket.bind(ipc_socket.c_str());

    LYSimpleTimerMgr *tm = new LYSimpleTimerMgr(remoteSocket);
    timerMgr = LYSimpleTimerMgrPtr(tm);

    // now wait for events to arrive
    timerMgr->run();

    // break was called, so exit
    return 0;
}

