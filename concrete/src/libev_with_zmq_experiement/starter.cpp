#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"
#include <ev.h>
#include "../../concrete/src/LYTimerManager.h"

#include "../../concrete/src/LYTimerManager.h"
#include "../../concrete/src/LYZmqEvent.h"

log4cplus::Logger logger;

LYTimerManagerPtr timerMgr;

zmq::context_t context(1);

zmq::socket_t remoteSocket(context, ZMQ_ROUTER);


/*
 * 1对1的服务子进程，包括给监控子进程，如果子进程退出，自己也退出。
 * 同时给子进程提供Timer功能
 * 启动子进程，参数1为子进程程序名
 * 同时启动Timer
 *
 */

//class LYTimerEvent : public LYZmqEvent
//{
//public:
//	LYTimerEvent(zmq::context_t& context, zmq::socket_t& socket) : LYZmqEvent(context, socket) {};
//	~LYTimerEvent() {};
//
//public:
//    // Function we are going to call to write to the ZeroMQ socket
//    void write() {};
//
//    // Function we are going to call to read from the ZeroMQ socket
//    void read();
//};
//
//void LYTimerEvent::read()
//{
//	std::cout << "msg arriving..." << std::endl;
//}

int main(int argc, char* argv[]) {
	logger = getLogger(argv[0]);
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <executable>" << std::endl;
		exit(-1);
	}

//	std::string ipc_socket = "ipc:///tmp/" + std::string(argv[1]);
	std::string ipc_socket = "tcp://0.0.0.0:5678";
LY_LOG_DBG("listening ..." << ipc_socket);
//	std::cout << ipc_socket << std::endl;

//	int child = fork();
//	if (child == 0){
//		execv(argv[1], NULL);
//		exit(0);
//	}
	//parent process
//	std::cout << ipc_socket << std::endl;

    remoteSocket.bind(ipc_socket.c_str());

//    std::cout << "before ..." << std::endl;
//    LYTimerEvent te(context, remoteSocket);
//    struct ev_loop *loop = ev_default_loop(0);
//    ev_loop(loop, 0);
//    std::cout << "after ..." << std::endl;


    LYTimerManager *tm = new LYTimerManager(remoteSocket);
    timerMgr = LYTimerManagerPtr(tm);

    // now wait for events to arrive
    timerMgr->run();

    // break was called, so exit
    return 0;
}

