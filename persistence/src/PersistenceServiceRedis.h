/*
 * PersistenceService redis implements.h
 *
 *  Created on: 2013-6-27
 *      Author: caiqingfeng
 */

#ifndef PERSISTENCESERVICEREDIS_H
#define PERSISTENCESERVICEREDIS_H

#include <hiredis/hiredis.h>
#include "PersistenceServiceDelegate.h"
#include <vector>
#include "common/src/my_log.h"

/*
 * Table embeds many trunks
 * Game is an independent collection to speed up record operation
 * Game has two fields table_id and trunk_id
 */
class PersistenceServiceRedis: public PersistenceServiceDelegate {
protected:
	redisContext* dbc;
public:
	void drop_collection(const std::string& collection);
	void clear_collections(const std::string& db_name);
	void reset_hash(const std::string& collection);
	void reset_zset(const std::string& collection);
	void rm_index_from_zset(const std::string& collection,
			const std::string& instance);
	void drop_hash(const std::string& collection, const std::string& instance);
	void add_index_to_zset(const std::string& collection,
			const std::string& idx);
	void copy_collection(const std::string& from_collection,
			const std::string& to_collection);
	void copy_hash_instance(const std::string& collection,
			const std::string& from_instance, const std::string& to_instance);
	void store_kvps_to_hash(const std::string& collection,
			const std::string& instance,
			std::vector<std::pair<std::string, std::string> >& kvps);
	void rm_member_to_hash(const std::string& collection,
			const std::string& instance); //added 20151220
	void retrieve_index_to_vector(const std::string& collection,
			std::vector<std::string>& list);
	void retrieve_hash_to_kvps(const std::string& collection,
			const std::string& instance,
			std::vector<std::pair<std::string, std::string> >& kvps);
	void retrieve_last_instance_to_kvps(const std::string& collection,
			std::vector<std::pair<std::string, std::string> >& kvps);
	void retrieve_hash_member_to_kvp(const std::string& collection,
			const std::string& instance, const std::string& key,
			std::pair<std::string, std::string>& kvp);
	void retrieve_latest_hash_index(const std::string& collection,
			std::string& latest_id);
	void rename_keys(const std::string& prefix, const std::string& from,
			const std::string& to);

public:
	PersistenceServiceRedis(const std::string& db_name);

public:
	virtual ~PersistenceServiceRedis();

	virtual void dropAllCollections(const std::string dbname = "test");

};

#endif /* PERSISTENCESERVICEREDIS_H */
