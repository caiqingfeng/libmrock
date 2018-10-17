/*
 * SessionM.h
 *
 *  Created on: 2013-3-6
 *      Author: tommy
 */

#ifndef SESSIONM_H_
#define SESSIONM_H_

#include <map>
#include <boost/utility.hpp>
#include <boost/foreach.hpp>
//#include <mongo/client/dbclient.h>
#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"
#include "Session.h"
#include "common/src/msg.pb.h"

using com::luyun::msg::OtaMsg;
using com::luyun::msg::OtaMulticast;
using com::luyun::msg::Session;
using std::string;

namespace com
{
namespace luyun
{
namespace msg
{

typedef boost::shared_ptr<Session> SessionPtr;
class SessionM: boost::noncopyable
{
private:
    std::map<string, SessionPtr> sessions; // uid to session map
    std::map<std::string, std::string> zmq_fast_index;
    zmq::socket_t& lan_socket;
    zmq::socket_t& wan_socket;
//    zmq::socket_t& json_socket;
    void sendKickOff(std::string origin_zid, std::string uid);
    void updateSession(OtaMsg& msg, const string& zmq_id);
    virtual void forwardMsg(string& msg, string& payload, const std::string pre_confirmed_service="");
    virtual void forwardJson(string& msg);
    void cleanDuplicateZmq(const std::string& zmq_id, const std::string& uid);

public:
    std::vector<std::string> service_addrs;
    SessionM(zmq::socket_t& lan_soc, zmq::socket_t& wan_soc) :
            lan_socket(lan_soc), wan_socket(wan_soc)
    {

    }
    virtual ~SessionM();
    void onWanMsg(string& connid, string& msg, string& payload, string& digest);
    void onJsonCall(string& msg);
    virtual bool isValid(string& msg, string& digest, OtaMsg& otaMsg);
    virtual string getKey(const string& uid);

    inline string getZmqId(string uid)
    {
        if (sessions.find(uid) != sessions.end())
        {
            return sessions[uid]->getConnId();
        }

        return "";
    }

    virtual void bcastMsg(zmq::socket_t& socket, string& msg);
    virtual void mcastMsg(zmq::socket_t& socket, string uids, string& msg);
    inline bool haveSession(const string& uid);
    void register_service(const std::string& service);
    std::string dispatcher(const std::string& pre_confirmed_service);
};

}
}
}

#endif /* SESSIONM_H_ */
