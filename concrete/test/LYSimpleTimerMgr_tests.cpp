/*
 * PersistenceServiceMysql_tests.cpp
 *
 *  Created on: 2014年10月17日
 *      Author: luyunstaff001
 */

#include "common/src/my_log.h"

#include <gtest/gtest.h>
#include <json/json.h>
#include "MessageStubs.h"

zmq::context_t context(1);

zmq::socket_t remoteSocket(context, ZMQ_ROUTER);

class LYSimpleTimerMgr_tests: public ::testing::Test {
public:

	void SetUp() {
		tm = new MockMsgHandler(remoteSocket);
	}

	void TearDown() {
		delete tm;
	}

public:
	MockMsgHandler *tm;
};

TEST_F(LYSimpleTimerMgr_tests, init)
{
	ASSERT_EQ(tm->timers.size(), 0);
}

TEST_F(LYSimpleTimerMgr_tests, buildMsg)
{
	LYTimerPtr t(new LYTimer);
	std::string msg;
	tm->buildTimerMsg(t, com::luyun::timer::shared::LY_TIMER_REG, msg);
	tm->onMsg("test", msg);
	ASSERT_EQ(tm->timers.size(), 1);
	tm->iterateAllTimers();
}

