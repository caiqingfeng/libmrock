/*
 * PersistenceServiceRedis.cpp
 *
 *  Created on: 2013-6-27
 *      Author: caiqingfeng
 */

#include <boost/foreach.hpp>
#include "PersistenceServiceRedis.h"
//#include "SerializeHelper.h"
#include <iostream>

PersistenceServiceRedis::PersistenceServiceRedis(const std::string& db_name) :
		PersistenceServiceDelegate(db_name) {
	// TODO Auto-generated constructor stub
	int timeout = 10000;
	struct timeval tv;
	tv.tv_sec = timeout / 1000;
	tv.tv_usec = timeout * 1000;
	//dbc = redisConnectWithTimeout("localhost", 6379, tv);
	dbc = redisConnect("localhost", 6379);
	if (dbc != NULL && dbc->err) {
		LY_LOG_ERR("error: " << dbc->errstr);
		std::cerr << "error: " << dbc->errstr;
	}
}

PersistenceServiceRedis::~PersistenceServiceRedis() {
	// TODO Auto-generated destructor stub
	redisFree(dbc);
}

/*
 * collection + instance_id, holdem_development.tables.51209ADxxxx
 */
void PersistenceServiceRedis::store_kvps_to_hash(const std::string& collection,
		const std::string& instance,
		std::vector<std::pair<std::string, std::string> >& kvps) {
	//set index first
	std::string cmd = "zadd " + collection + ".index" + " 1 " + instance;
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		LY_LOG_ERR("error happend! " << std::string(reply->str));
	}
	freeReplyObject(reply);

	//set key-value-pairs
	std::vector<std::pair<std::string, std::string> >::iterator it =
			kvps.begin();
	cmd = "hmset " + collection + "." + instance;
	for (; it != kvps.end(); it++) {
		std::pair < std::string, std::string > kvp = *it;
		if (kvp.second == "") {
//			LY_LOG_ERR(
//					"error, cannot be empty string due to restrict of redis");
			kvp.second = "NULL";
		}
		cmd = cmd + " " + kvp.first + " " + kvp.second;
	}
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr
						<< " cmd=" << cmd);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
		LY_LOG_ERR("error happend! " << std::string(reply->str) << " cmd=" << cmd);
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::rm_member_to_hash(const std::string& collection,
			const std::string& instance) //added 20151220
{
	//delete key-value-pairs
	std::string cmd = "hdel " + collection + " " + instance;
//	std::cout << cmd << std::endl;
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = NULL;
	reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	if (reply->type == REDIS_REPLY_ERROR) {
	std::cout << "ddddd = " <<  std::endl;
		LY_LOG_ERR("error happend! " << std::string(reply->str));
	}
	freeReplyObject(reply);

	rm_index_from_zset(collection + ".index", instance);
}

void PersistenceServiceRedis::retrieve_hash_to_kvps(
		const std::string& collection, const std::string& instance,
		std::vector<std::pair<std::string, std::string> >& kvps) {
	kvps.clear();

	//check index first
	std::string cmd = "zrevrank " + collection + ".index" + " " + instance;
//	if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
//		LY_LOG_ERR("redis failed at " << cmd);
//		return;
//	}
	cmd = "hgetall " + collection + "." + instance;
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
		LY_LOG_ERR("redis failed at " << cmd);
		return;
	}
	redisReply *reply = NULL;
//	if (REDIS_OK != redisGetReply(dbc,(void**)&reply)) {
//		LY_LOG_ERR("redisGetReply failed ");
//		freeReplyObject(reply);
//		return;
//	}
//	//check if index includes that session instance here
//	if (reply->type != REDIS_REPLY_INTEGER) {
//		LY_LOG_ERR("no such object " << instance );
//		freeReplyObject(reply);
//		return;
//	}
//	freeReplyObject(reply);

	if (REDIS_OK != redisGetReply(dbc, (void**) &reply)) {
		LY_LOG_ERR("redisGetReply failed " << ", cmd=" << cmd);
		freeReplyObject(reply);
		return;
	}
	//check if index includes that session instance here
	if (reply->type != REDIS_REPLY_ARRAY || reply->elements < 1) {
		LY_LOG_ERR(
				"no such hash, will destory that " << instance << ", cmd="
						<< cmd);
		freeReplyObject(reply);
		cmd = "zrem " + collection + ".index" + " " + instance;
		if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
			LY_LOG_ERR("redis failed at " << cmd);
			return;
		}
		if (REDIS_OK != redisGetReply(dbc, (void**) &reply)) {
			LY_LOG_ERR("redisGetReply failed " << ", cmd=" << cmd);
			freeReplyObject(reply);
			return;
		}
		freeReplyObject(reply);
		return;
	}
	//set key-value-pairs
	for (int i = 0; i < reply->elements / 2; i++) {
		std::pair < std::string, std::string > kvp;
		kvp.first = reply->element[2 * i]->str;
		kvp.second = reply->element[2 * i + 1]->str;
		kvps.push_back(kvp);
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::retrieve_index_to_vector(
		const std::string& collection, std::vector<std::string>& list) {
	list.clear();

	std::string cmd = "zrange " + collection + ".index" + " 0 -1";
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	switch (reply->type) {
	case REDIS_REPLY_ARRAY: {
		for (int i = 0; i < reply->elements; i++) {
			redisReply *r = reply->element[i];
			if (r->type == REDIS_REPLY_STRING) {
				std::string sid = r->str;
				list.push_back(sid);
			}
		}
	}
		break;
	case REDIS_REPLY_STRING: {
		std::string sid = reply->str;
		list.push_back(sid);
	}
		break;
	default:
		break;
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::retrieve_hash_member_to_kvp(
		const std::string& collection, const std::string& instance,
		const std::string& key, std::pair<std::string, std::string>& kvp) {
	std::string cmd = "hget " + collection + "." + instance + " " + key;
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	switch (reply->type) {
	case REDIS_REPLY_STRING: {
		std::string sid = reply->str;
		kvp.second = sid;
	}
		break;
	default:
		break;
	}
	freeReplyObject(reply);
}
void PersistenceServiceRedis::rm_index_from_zset(const std::string& collection,
		const std::string& instance) {
	std::string cmd = "zrem " + collection + " " + instance;
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
		LY_LOG_ERR("redis failed at " << cmd);
		return;
	}
	redisReply *reply = NULL;
	if (REDIS_OK != redisGetReply(dbc, (void**) &reply)) {
		LY_LOG_ERR("redisGetReply failed ");
		freeReplyObject(reply);
	}
}
void PersistenceServiceRedis::retrieve_latest_hash_index(
		const std::string& collection, std::string& latest_id) {
	std::string cmd = "zrange " + collection + ".index" + " -1 -1";
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	switch (reply->type) {
	case REDIS_REPLY_ARRAY: {
		for (int i = 0; i < reply->elements; i++) {
			redisReply *r = reply->element[i];
			if (r->type == REDIS_REPLY_STRING) {
				std::string sid = r->str;
				latest_id = sid;
			}
		}
	}
		break;
	case REDIS_REPLY_STRING: {
		std::string sid = reply->str;
		latest_id = sid;
	}
		break;
	default:
		break;
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::reset_hash(const std::string& collection) {
	std::string cmd = "zrange " + collection + ".index" + " 0 -1";
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	switch (reply->type) {
	case REDIS_REPLY_ARRAY: {
		for (int i = 0; i < reply->elements; i++) {
			redisReply *r = reply->element[i];
			if (r->type == REDIS_REPLY_STRING) {
				std::string sid = r->str;
				cmd = "del " + collection + "." + sid;
				redisReply *reply2 = (redisReply *) redisCommand(dbc,
						cmd.c_str());
				if (reply2 == NULL) {
					LY_LOG_ERR(
							"fatal error happend! error code:" << dbc->err
									<< ", error string:" << dbc->errstr);
					redisFree(dbc);
					dbc = NULL;
					return;
				}
				freeReplyObject(reply2);
			}
		}
	}
		break;
	case REDIS_REPLY_STRING: {
		std::string sid = reply->str;
		cmd = "del " + collection + "." + sid;
		redisReply *reply2 = (redisReply *) redisCommand(dbc, cmd.c_str());
		if (reply2 == NULL) {
			LY_LOG_ERR(
					"fatal error happend! error code:" << dbc->err
							<< ", error string:" << dbc->errstr);
			redisFree(dbc);
			dbc = NULL;
			return;
		}
		freeReplyObject(reply2);
	}
		break;
	default:
		break;
	}
	freeReplyObject(reply);

	//remove indexes
	cmd = "ZREMRANGEBYRANK " + collection + ".index" + " 0 -1";
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::reset_zset(const std::string& collection) {
	std::string cmd = "ZREMRANGEBYRANK " + collection + ".index" + " 0 -1";
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	switch (reply->type) {
	default:
		break;
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::add_index_to_zset(const std::string& collection,
		const std::string& idx) {
	std::string cmd = "zadd " + collection + ".index" + " 1 " + idx;
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	redisReply *reply = (redisReply *) redisCommand(dbc, cmd.c_str());
	if (reply == NULL) {
		LY_LOG_ERR(
				"fatal error happend! error code:" << dbc->err
						<< ", error string:" << dbc->errstr);
		redisFree(dbc);
		dbc = NULL;
		return;
	}
	switch (reply->type) // check return
	{
	default:
		break;
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::copy_collection(
		const std::string& from_collection, const std::string& to_collection) {
	std::vector < std::string > list;
	retrieve_index_to_vector(from_collection, list);
	std::vector<std::string>::iterator it = list.begin();
	for (; it != list.end(); it++) {
		std::string instance = *it;
		std::vector < std::pair<std::string, std::string> > kvps;
		retrieve_hash_to_kvps(from_collection, instance, kvps);
		store_kvps_to_hash(to_collection, instance, kvps);
	}
}

void PersistenceServiceRedis::copy_hash_instance(const std::string& collection,
		const std::string& from_instance, const std::string& to_instance) {
	std::vector < std::pair<std::string, std::string> > kvps;
	retrieve_hash_to_kvps(collection, from_instance, kvps);
	drop_hash(collection, from_instance);
	store_kvps_to_hash(collection, to_instance, kvps);
}

void PersistenceServiceRedis::drop_hash(const std::string& collection,
		const std::string& instance) {
	std::string cmd = "del " + collection + "." + instance;
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
//std::cout << cmd << std::endl;
	if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
		LY_LOG_ERR("redis failed at " << cmd);
		return;
	}
	redisReply *reply = NULL;
	if (REDIS_OK != redisGetReply(dbc, (void**) &reply)) {
		LY_LOG_ERR("redisGetReply failed ");
		freeReplyObject(reply);
	}
}

void PersistenceServiceRedis::retrieve_last_instance_to_kvps(
		const std::string& collection,
		std::vector<std::pair<std::string, std::string> >& kvps) {
	std::string lates_instance;
	retrieve_latest_hash_index(collection, lates_instance);
	retrieve_hash_to_kvps(collection, lates_instance, kvps);
}

//drop all collections belong to that db
void PersistenceServiceRedis::dropAllCollections(const std::string dbname) {
	if (dbname != "test") {
		LY_LOG_ERR(
				"only support drop collections for test!"
						<< std::string(dbname));
		return;
	}
	clear_collections(dbname);
	return;
}

void PersistenceServiceRedis::drop_collection(const std::string& collection) {
	//access index to get all instance
	std::vector < std::string > list;
	retrieve_index_to_vector(collection, list);
	std::vector<std::string>::iterator it = list.begin();
	for (; it != list.end(); it++) {
		std::string instance = *it;
		std::string cmd = "del " + collection + "." + instance;
		LY_LOG_DBG("for debug redis cmd:" << cmd);
		if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
			LY_LOG_ERR("redis failed at " << cmd);
			return;
		}
	}
	std::string cmd = "del " + collection + ".index";
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
		LY_LOG_ERR("redis failed at " << cmd);
		return;
	}
	for (int i = 0; i < list.size() + 1; i++) {
		redisReply *reply = NULL;
		if (REDIS_OK != redisGetReply(dbc, (void**) &reply)) {
			LY_LOG_ERR("redisGetReply failed ");
			freeReplyObject(reply);
//			return;
		}
	}
}

void PersistenceServiceRedis::clear_collections(const std::string& db_name) {
	if (db_name != "test") {
		LY_LOG_ERR("only support dropping test collections!");
		return;
	}
	//access index to get all instance
	std::string cmd = "keys " + dbName + "_test.*";
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
		LY_LOG_ERR("redis failed at " << cmd);
		return;
	}
	redisReply *reply = NULL;
	if (REDIS_OK != redisGetReply(dbc, (void**) &reply)) {
		LY_LOG_ERR("redisGetReply failed ");
		freeReplyObject(reply);
//			return;
	}
	switch (reply->type) {
	case REDIS_REPLY_ARRAY: {
		for (int i = 0; i < reply->elements; i++) {
			redisReply *r = reply->element[i];
			if (r->type == REDIS_REPLY_STRING) {
				std::string sid = r->str;
				cmd = "del " + sid;
				LY_LOG_DBG("for debug redis cmd:" << cmd);
				redisReply *reply2 = (redisReply *) redisCommand(dbc,
						cmd.c_str());
				if (reply2 == NULL) {
					LY_LOG_ERR(
							"fatal error happend! error code:" << dbc->err
									<< ", error string:" << dbc->errstr);
					redisFree(dbc);
					dbc = NULL;
					return;
				}
				freeReplyObject(reply2);
			}
		}
	}
		break;
	default:
		break;
	}
	freeReplyObject(reply);
}

void PersistenceServiceRedis::rename_keys(const std::string& prefix,
		const std::string& from, const std::string& to) {
	//access index to get all instance
	std::string cmd = "keys " + prefix + "." + from + "*";
	int from_start = prefix.length() + 1;
	int from_len = from.length();
//	LY_LOG_DBG("for debug redis cmd:" << cmd);
	if (REDIS_OK != redisAppendCommand(dbc, cmd.c_str())) {
		LY_LOG_ERR("redis failed at " << cmd);
		return;
	}
	redisReply *reply = NULL;
	if (REDIS_OK != redisGetReply(dbc, (void**) &reply)) {
		LY_LOG_ERR("redisGetReply failed ");
		freeReplyObject(reply);
//			return;
	}
	switch (reply->type) {
	case REDIS_REPLY_ARRAY: {
		for (int i = 0; i < reply->elements; i++) {
			redisReply *r = reply->element[i];
			if (r->type == REDIS_REPLY_STRING) {
				std::string origin_key = r->str;
				std::string sid = origin_key;
				std::string new_key = sid.replace(from_start, from_len, to);
				cmd = "del " + new_key;
				LY_LOG_DBG("for debug redis cmd:" << cmd);
				redisReply *reply2 = (redisReply *) redisCommand(dbc,
						cmd.c_str());
				if (reply2 == NULL) {
					LY_LOG_ERR(
							"fatal error happend! error code:" << dbc->err
									<< ", error string:" << dbc->errstr);
					redisFree(dbc);
					dbc = NULL;
					return;
				}
				freeReplyObject(reply2);

				cmd = "rename " + origin_key + " " + new_key;
				LY_LOG_DBG("for debug redis cmd:" << cmd);
				reply2 = (redisReply *) redisCommand(dbc, cmd.c_str());
				if (reply2 == NULL) {
					LY_LOG_ERR(
							"fatal error happend! error code:" << dbc->err
									<< ", error string:" << dbc->errstr);
					redisFree(dbc);
					dbc = NULL;
					return;
				}
				freeReplyObject(reply2);
			}
		}
	}
		break;
	default:
		break;
	}
	freeReplyObject(reply);
}
