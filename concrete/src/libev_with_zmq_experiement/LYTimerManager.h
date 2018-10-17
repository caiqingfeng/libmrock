/*
 * LYTimerManager.h
 *
 *  Created on: 2013-5-3
 *      Author: caiqingfeng
 */

#ifndef LYTIMERMANAGER_H_
#define LYTIMERMANAGER_H_

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

#include "common/src/zhelpers.hpp"
#include "common/src/my_log.h"

#include "common/src/LYTimer.h"

extern zmq::context_t context;

class LYTimerManager {

public:
	LYTimerManager(zmq::socket_t &rm);
	virtual ~LYTimerManager();
	void run();
	void handleNW();
	void onMsg(const std::string &from, const std::string &msg);
	void onTimeout(const std::string &timerId);

private:
	std::map<std::string, LYTimerPtr> timers;
	struct ev_loop *loop;

public:
	zmq::socket_t& remote; //n/w socket

};

typedef boost::shared_ptr<LYTimerManager> LYTimerManagerPtr;

#endif /* LYTIMERMANAGER_H_ */
