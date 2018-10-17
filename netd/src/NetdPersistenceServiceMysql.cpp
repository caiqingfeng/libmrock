/*
 * MysqlPersistence.cpp
 *
 *  Created on: 2013-9-11
 *      Author: chenfeng
 */

#include "NetdPersistenceServiceMysql.h"
#include "common/src/my_log.h"
#include <string>
#include <boost/lexical_cast.hpp>

NetdPersistenceServiceMysql::NetdPersistenceServiceMysql(const std::string& db_name) :
		PersistenceServiceMysql(db_name)
{
}

NetdPersistenceServiceMysql::~NetdPersistenceServiceMysql() {
    // TODO Auto-generated destructor stub
}

void NetdPersistenceServiceMysql::clean_db() {
    // TODO Auto-generated destructor stub
}
std::string NetdPersistenceServiceMysql::getKey(const std::string& uid)
{
	return "62c6e8ee0c06df7d";
}

