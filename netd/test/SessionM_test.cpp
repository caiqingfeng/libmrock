#include <gtest/gtest.h>
#include "common/src/my_log.h"
#include "netd/src/SessionM.h"
#include "common/src/msg.pb.h"

zmq::context_t context(1);
zmq::socket_t lan(context, ZMQ_PAIR);
//zmq::socket_t wan(context, ZMQ_PAIR);

class SessionM_tests: public ::testing::Test
{
protected:

    void SetUp()
    {
//    	sm = new com::luyun::msg::SessionM(lan, wan);
    }

    void TearDown()
    {
 //   	delete sm;
    }

public:
    com::luyun::msg::SessionM* sm;

};
TEST_F(SessionM_tests, isValid)
{
//	OtaMsg msg;
//	msg.set_uid("huafeng01");
//	std::string payload = "kkkk";
//	std::string digest = "FD8FF6660D8AC0B70CCAF1BE6572095C";
//	ASSERT_EQ(true, sm->isValid(payload, digest, msg));
}
