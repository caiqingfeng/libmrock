/*
 * MysqlPersistence.h
 *
 *  Created on: 2014-4-11
 *      Author: cqf
 */

#ifndef NETDPERSISTENCEMYSQL_H_
#define NETDPERSISTENCEMYSQL_H_

#include "persistence/src/PersistenceService.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <vector>

#include "persistence/src/PersistenceServiceMysql.h"

class NetdPersistenceServiceMysql: public PersistenceServiceMysql {
public:
	NetdPersistenceServiceMysql(const std::string& db_name);

public:
    virtual ~NetdPersistenceServiceMysql();
    virtual void clean_db();

	virtual std::string getKey(const std::string& uid);
};

#endif /* APPDPERSISTENCEMYSQL_H_ */
