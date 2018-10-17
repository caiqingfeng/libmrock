#include <gtest/gtest.h>

#include "MessageStubs.h"
#include "common/src/my_log.h"


class MsgHandler_tests : public ::testing::Test
{
protected:

    void SetUp()
    {
    	zmq::context_t context(1);
    	zmq::socket_t g_socketLocalSvr(context, ZMQ_PAIR);
    	handler = new MockMsgHandler(g_socketLocalSvr);
    	std::string uid = "huafeng01";
    	std::string key = "62c6e8ee0c06df7d";
    	handler->setUidAndKey(uid, key);
    }
    void TearDown()
    {
   }
public:
    MockMsgHandler *handler;
};

TEST_F(MsgHandler_tests, sendCryptoMsg)
{
	std::string msg("kkkk");
	handler->sendCryptoMsg(msg);
}
