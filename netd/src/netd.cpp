#include "common/src/zhelpers.hpp"
#include "SessionM.h"
#include "NetdPersistenceService.h"
#include "common/src/LYZhelpers.hpp"
#include "common/src/LYUtils.h"
using namespace std;
using namespace boost;
using namespace com::luyun::msg;

log4cplus::Logger logger;

int main(int argc, char* argv[]) {
	logger = getLogger(argv[0]);
	char *server_base = getenv("LUYUN_SERVER_BASE");
	std::string wan_port = "9001";
	std::string lan_port = "9002";
	std::string web_port = "9003";
//    std::string json_port = "9004";
	if (server_base != NULL) {
		int base_port = atoi(server_base);
		char buf[20];
		memset(buf, 0, 20);
		sprintf(buf, "%d", base_port + 1);
		wan_port = buf;
		memset(buf, 0, 20);
		sprintf(buf, "%d", base_port + 2);
		lan_port = buf;
		memset(buf, 0, 20);
		sprintf(buf, "%d", base_port + 3);
		web_port = buf;
//        memset(buf, 0, 20);
//        sprintf(buf, "%d", base_port + 4);
//        json_port = buf;
	}

	LY_LOG_INF("listening..." << wan_port);
	zmq::context_t context(1);

	zmq::socket_t wan_socket(context, ZMQ_ROUTER);
	std::string wan_server = "tcp://*:" + wan_port;
	wan_socket.bind(wan_server.c_str());

	zmq::socket_t lan_socket(context, ZMQ_ROUTER);
	std::string lan_server = "tcp://127.0.0.1:" + lan_port;
	lan_socket.bind(lan_server.c_str());

//    zmq::socket_t json_socket(context, ZMQ_ROUTER); //one way socket, only for netd to appd
//    std::string json_server = "tcp://127.0.0.1:" + json_port;
//    json_socket.bind(json_server.c_str());
//
	zmq::socket_t web_socket(context, ZMQ_ROUTER);
	std::string web_server = "tcp://*:" + web_port;
	web_socket.bind(web_server.c_str());

	zmq::pollitem_t items[] = { { wan_socket, 0, ZMQ_POLLIN, 0 }, { lan_socket,
			0, ZMQ_POLLIN, 0 }, { web_socket, 0, ZMQ_POLLIN, 0 } };

	SessionM* pSessionM = new SessionM(lan_socket, wan_socket);
	//会在s_recv_multipart中clear一次,因此每次接收消息时它都以空状态填入数据
	std::vector < std::string > whole_msg;
	//loop for waiting connection
	while (true) {
		zmq::poll(&items[0], 3, -1);

		// app client
		//客户端消息有 Pioneermessage
		if (items[0].revents & ZMQ_POLLIN) {
//			LY_LOG_DBG("receive msg from app client");
			s_recv_multipart(wan_socket, whole_msg);
			LYUtils::printTextOrBinary(std::string("zmq_id:"), whole_msg[0]);
			//客户端不设置 zmq id
			std::string zmq_id, msg = "", payload = "", digest = "";
			if (whole_msg.size() == 2) {
				if (whole_msg[1] == "SK") {
					LY_LOG_INF("is_shake_hands");
				} else {
					LY_LOG_INF("invalid msg!");
				}
				continue;
			} else if (whole_msg.size() == 4) {
				zmq_id = whole_msg[0];
				msg = whole_msg[1];
				payload = whole_msg[2];
				digest = whole_msg[3];
			} else if (whole_msg.size() == 7) {
				zmq_id = whole_msg[0];
				for (int i = 1; i < 6; i = i + 2) {
					if (whole_msg[i] == "m") {
						msg = whole_msg[i + 1];
					} else if (whole_msg[i] == "p") {
						payload = whole_msg[i + 1];
					} else if (whole_msg[i] == "d") {
						digest = whole_msg[i + 1];
					}
				}
			} else {
				LY_LOG_INF("invalid msg!");
				continue;
			}
			pSessionM->onWanMsg(zmq_id, msg, payload, digest);
		}

		// app server: forward
		//服务器侧没有pionner message
		if (items[1].revents & ZMQ_POLLIN) {
			LY_LOG_DBG("receive msg from app server");

			string addr = s_recv(lan_socket);
			string uid = s_recv(lan_socket);

			if (uid == "ready") {
				pSessionM->register_service(addr);
			} else if (uid == LY_BCAST) {
				// broadcast
				LY_LOG_DBG("broadcast!");
				string msg = s_recv(lan_socket);
				pSessionM->bcastMsg(wan_socket, msg);
			} else if (uid == LY_MCAST) {
				// multicast
				string uids = s_recv(lan_socket);
				string msg = s_recv(lan_socket);
				pSessionM->mcastMsg(wan_socket, uids, msg);
			} else {
				string msg = s_recv(lan_socket);
				string conn_id = pSessionM->getZmqId(uid);
				if (conn_id != "") {
					s_sendmore(wan_socket, conn_id);
					s_send(wan_socket, msg);
				} else {
					LY_LOG_DBG("fail to find conn id: " << uid);
				}
			}
		}

		// web server: forward
		if (items[2].revents & ZMQ_POLLIN) {
			LY_LOG_DBG("receive msg from web server");

			string addr = s_recv(web_socket);
			string uid = s_recv(web_socket);

			if (uid == LY_BCAST) {
				// broadcast
				LY_LOG_DBG("broadcast!");
				string msg = s_recv(web_socket);
				pSessionM->bcastMsg(wan_socket, msg);
			} else if (uid == LY_MCAST) {
				// multicast
				string uids = s_recv(web_socket);
				string msg = s_recv(web_socket);
				pSessionM->mcastMsg(wan_socket, uids, msg);
			} else if (uid == LY_FEED) {
				//to feed server
				string msg = s_recv(web_socket);
				pSessionM->onJsonCall(msg);
			} else {
				string msg = s_recv(web_socket);
				string conn_id = pSessionM->getZmqId(uid);
				if (conn_id != "") {
					s_sendmore(wan_socket, conn_id);
					s_send(wan_socket, msg);
				} else {
					LY_LOG_DBG("fail to find conn id: " << uid);
				}
			}
		}
	}

	delete pSessionM;
}

