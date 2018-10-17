/*
 * PersistenceServiceDelegate_tests.cpp
 *
 *  Created on: 2014-4-14
 *      Author: caiqingfeng
 */

#include "persistence/src/PersistenceServiceDelegate.h"
#include "common/src/my_log.h"

#include <gtest/gtest.h>

class PersistenceServiceDelegate_tests : public ::testing::Test{
public:

    void SetUp()
    {
    	psd = new PersistenceServiceDelegate("ryiwan");
    }

    void TearDown()
    {
        delete psd;
    }

public:
    PersistenceServiceDelegate* psd;
};

TEST_F(PersistenceServiceDelegate_tests, init)
{
	ASSERT_EQ(psd->railsEnv, "test");
	ASSERT_EQ(psd->dbName, "ryiwan");
}

