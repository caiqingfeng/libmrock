#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "common/src/my_log.h"
#include "backend/src/setup_env.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    logger = getLogger("test");

    setupZmq();
    //setupPersistenceService();

    return RUN_ALL_TESTS();
}
