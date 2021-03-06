#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "common/src/my_log.h"
#include "frontend/src/setup_env.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    logger = getLogger("test");
    return RUN_ALL_TESTS();
}
