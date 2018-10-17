#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"
#include "libmrock/common/src/timer.pb.h"
#include <boost/thread.hpp>
#include "LYSimpleTimerMgr.h"

log4cplus::Logger logger;

LYSimpleTimerMgrPtr timerMgr;

zmq::context_t context(1);

zmq::socket_t remoteSocket(context, ZMQ_DEALER);

using namespace com::luyun::timer::shared;
using namespace com::luyun::timer;

void network_thread()
{
	zmq::socket_t& rmt(remoteSocket);
    zmq::pollitem_t items[] = {
            { rmt, 0, ZMQ_POLLIN, 0 }
    };
    while (1) {
        zmq::poll(&items[0], 1, -1);
        std::string msg_received;

         if (items[0].revents & ZMQ_POLLIN)
         {
         	LY_LOG_DBG("message from timer ... ");
             msg_received = s_recv(rmt);
         }
//		std::string msg_received = s_recv(remoteSocket);
		LYTimerMsg tmsg;
		try {
			tmsg.ParseFromString(msg_received);
		} catch (std::exception &e){
			LY_LOG_ERR("exception!" << e.what());
		}
		std::cout << tmsg.DebugString();
		//exit(0);
    }

}

int main(int argc, char* argv[])
{
    logger = getLogger(argv[0]);
	if (argc < 2) {
		std::cout << "Usage: timerc <ipcsocket> " << std::endl;
		return 0;
	}

    std::string server_addr = "ipc:///tmp/" + std::string(argv[1]);
//    std::string server_addr = "tcp://172.16.0.106:5678";

    remoteSocket.connect(server_addr.c_str());
    // now send string to server
    std::string msg;
    LYTimerMsg timerMsg;
    timerMsg.set_version(1);
    timerMsg.set_action(LY_TIMER_REG);
    timerMsg.set_after(5.5);
    timerMsg.set_repeat(0.0);
    timerMsg.SerializeToString(&msg);
//    s_sendmore(remoteSocket, "kkkk");
    s_send(remoteSocket, msg);
    
    std::string msg2;
    LYTimerMsg timerMsg2;
    timerMsg2.set_version(1);
    timerMsg2.set_action(LY_TIMER_REG);
    timerMsg2.set_after(5.5);
    timerMsg2.set_repeat(10.0);
    timerMsg2.set_will_stop_at(60.0+time(NULL));
    timerMsg2.SerializeToString(&msg2);
    s_send(remoteSocket, msg2);

    boost::thread *net = new boost::thread(boost::bind(&network_thread));
    net->join();
    std::cout << "net thread shutdown" << std::endl;
    // break was called, so exit
    return 0;
}

