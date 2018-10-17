#include <gtest/gtest.h>
#include "common/src/my_log.h"
#include "common/src/alg.h"

extern log4cplus::Logger logger;
using namespace std;
class AlgTest: public ::testing::Test
{
protected:

    void SetUp()
    {
    }

    void TearDown()
    {
    }

};
using namespace CryptoPP;
using std::string;
TEST_F(AlgTest, hmac_1)
{
    string token = "7a943ea7ccbb492d2750c287427fc912";
//    cout << "token size: " << token.size() << endl;

    string plain = "HMAC test";
    string mac, encoded;

//    cout << "key: " << token << endl;
//    cout << "plain text: " << plain << endl;

    try
    {
        HMAC<MD5> hmac((byte*) token.data(), token.size());

        StringSource(plain, true, new HashFilter(hmac, new StringSink(mac)) // HashFilter
                );// StringSource
    } catch (const CryptoPP::Exception& e)
    {
        cerr << e.what() << endl;
        exit(1);
    }

    encoded.clear();
    StringSource(mac, true, new HexEncoder(new StringSink(encoded)) // HexEncoder
            );// StringSource

//    cout << "hmac: " << encoded << endl;

    LY_LOG_INF("hmac: "<< encoded);

    ASSERT_TRUE(1 == 1);
}

