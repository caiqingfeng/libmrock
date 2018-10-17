/*
 * MysqlPersistence.h
 *
 *  Created on: 2013-9-11
 *      Author: chenfeng
 */

#ifndef PERSISTENCEMYSQL_H_
#define PERSISTENCEMYSQL_H_

#include "PersistenceService.h"
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <json/json.h>

class PersistenceServiceMysql: public PersistenceServiceDelegate {
protected:
	sql::Driver *driver;
	sql::Connection *con;

public:
	PersistenceServiceMysql(const std::string& db_name);

public:
	virtual ~PersistenceServiceMysql();
	void clean_table(const std::string& tbl);
	unsigned int fetch_last_id(const std::string& tbl);
	//0 int, 1 string, 2 datetime. datetime:UNIX_TIMESTAMP(last_sign_date) as last_sign_date
	void getJsonDataBySql(const std::string& sql,
			std::map<std::string, int> fileds,
			std::vector<Json::Value>& results);
	void getDataBySql(const std::string& sql,
			std::map<std::string, int>& fileds,
			std::vector<std::map<std::string, std::string> >& results);
};

#endif /* APPDPERSISTENCEMYSQL_H_ */
