/*
 * LYUtils_tests.cpp
 *
 *  Created on: 2014年10月13日
 *      Author: luyunstaff001
 */

#include <gtest/gtest.h>

#include "common/src/LYUtils.h"
#include "common/src/my_log.h"


class LYUtils_tests : public ::testing::Test
{
protected:

    void SetUp()
    {
    }
    void TearDown()
    {
   }
public:
    LYUtils utils;

};

TEST_F(LYUtils_tests, init)
{
	ASSERT_EQ(utils.genId().size(), 24);
//	for (int i=0; i<10; i++) {
//		std::cout << utils.genId() << std::endl;
//	}
	std::string aid = LYUtils::genId();
	std::string bid = LYUtils::genId();
	ASSERT_NE(aid, bid);
}

TEST_F(LYUtils_tests, genDigest)
{
	std::string payload =  "kkkk";
	std::string key = "62c6e8ee0c06df7d";
	std::string digest;
	utils.genDigest(payload, key, digest);

	ASSERT_EQ(digest, "FD8FF6660D8AC0B70CCAF1BE6572095C");
}
