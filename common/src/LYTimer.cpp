/*
 * LYTimer.cpp
 *
 *  Created on: 2013-5-3
 *      Author: caiqingfeng
 */

#include "LYTimer.h"
#include <boost/lexical_cast.hpp>
#include <iostream>

using namespace com::luyun::timer::shared;

LYTimer::LYTimer()
{
	after = 0.0;
	repeat = 0.0;
	will_stop_at = 0.0;
	action = LY_TIMER_REG;
	client_reserved1 = 0;
	client_reserved2 = 0;
	client_reserved3 = 0;
	client_reserved4 = 0;
	client_reserved5 = 0;
	client = "";
	server_timer_id = "";
	client_timer_id = "";
	second_client_timer_id = "";

	long *to = new long;
	boost::shared_ptr<long > to_ptr(to);
	time_out = to_ptr;
}

LYTimer::LYTimer(const std::string &cli, float af, float re) {
	// TODO Auto-generated constructor stub
	after = 0.0;
	repeat = 0.0;
	will_stop_at = 0.0;
	action = LY_TIMER_REG;
	client_reserved1 = 0;
	client_reserved2 = 0;
	client_reserved3 = 0;
	client_reserved4 = 0;
	client_reserved5 = 0;
	client = "";
	server_timer_id = "";
	client_timer_id = "";
	second_client_timer_id = "";

	client = cli;
	after = af;
	repeat = re;
//	ev_timer *to = new ev_timer();
//	boost::shared_ptr<ev_timer> to_ptr(to);
	long *to = new long;
	boost::shared_ptr<long > to_ptr(to);
	time_out = to_ptr;
}

LYTimer::~LYTimer() {
	// TODO Auto-generated destructor stub
}

void LYTimer::onTimeout()
{
	std::cout << "timeout event fires!" << this << std::endl;
}

std::string LYTimer::toString()
{
	std::string spb;
	spb = "after:" + boost::lexical_cast<std::string>(after) + ","
			+ "repeat:" + boost::lexical_cast<std::string>(repeat) + ","
			+ "will_stop_at:" + boost::lexical_cast<std::string>(will_stop_at) + ","
			+ "action:" + boost::lexical_cast<std::string>(action)
		;
	return spb;
}

bool LYTimer::go_fire(time_t now)
{
	if (next_fire_at > now) return false;
	return true;
}

void LYTimer::set_next_fire_at(time_t t)
{
	next_fire_at = t;
}
