/*
 * MysqlPersistence.cpp
 *
 *  Created on: 2014-4-14
 *      Author: caiqingfeng
 */

#include "PersistenceServiceMysql.h"
#include "common/src/my_log.h"

PersistenceServiceMysql::PersistenceServiceMysql(const std::string& db_name) :
		PersistenceServiceDelegate(db_name) {
	// TODO Auto-generated constructor stub
	try {
		string host = "tcp://127.0.0.1:3306";
		string user = "root";
		string password = "root";
		char *db_host = getenv("MYSQL_HOST");
		if (db_host != NULL) {
			host = string(db_host);
		}
		char *db_username = getenv("MYSQL_USER");
		if (db_username != NULL) {
			user = string(db_username);
		}
		char *db_pwd = getenv("MYSQL_PWD");
		if (db_pwd != NULL) {
			password = string(db_pwd);
		}

		string database = db_name + "_" + railsEnv;
		LY_LOG_DBG("password: " << password << ", database: " << database);

		driver = get_driver_instance();
		sql::ConnectOptionsMap connectionProperties;
		connectionProperties["hostName"] = host;
		connectionProperties["userName"] = user;
		connectionProperties["password"] = password;
		connectionProperties["OPT_CONNECT_TIMEOUT"] = 600;
		connectionProperties["OPT_RECONNECT"] = true;
		con = driver->connect(connectionProperties);
		LY_LOG_INF("db connect succeed");

		/* Connect to the MySQL test database */
//		std::cout << database << std::endl;
		con->setSchema(database);
	} catch (sql::SQLException &e) {
		std::cout << "mysql SQLException: " << e.what() << std::endl;
		LY_LOG_ERR("mysql SQLException: " << e.what());
	}
}

PersistenceServiceMysql::~PersistenceServiceMysql() {
	// TODO Auto-generated destructor stub
	delete con;
}

void PersistenceServiceMysql::clean_table(const std::string& tbl) {
	try {
		/* '?' is the supported placeholder syntax */
		std::string statement = std::string("DELETE ") + std::string("FROM ")
				+ tbl;
		sql::PreparedStatement *pstmt = con->prepareStatement(
				statement.c_str());
		int res = pstmt->executeUpdate();

		if (res > 0) {
			LY_LOG_DBG("clean success");
		}
		delete pstmt;
		return;
	} catch (sql::SQLException &e) {
		LY_LOG_ERR("mysql SQLException: " << e.what());
	}

	return;
}

unsigned int PersistenceServiceMysql::fetch_last_id(const std::string& tbl) {
	try {
		/* '?' is the supported placeholder syntax */
		std::string statement = std::string("SELECT id ") + std::string("FROM ")
				+ tbl + " ORDER BY ID DESC LIMIT 1";
		sql::PreparedStatement *pstmt = con->prepareStatement(
				statement.c_str());
		sql::ResultSet *res = pstmt->executeQuery();

		unsigned int index = 0;
		if (res->next()) {
			index = (unsigned int) res->getInt("id");
		}
		delete res;
		delete pstmt;
		return index;
	} catch (sql::SQLException &e) {
		LY_LOG_ERR("mysql SQLException: " << e.what());
	}

	return 0;
}

void PersistenceServiceMysql::getJsonDataBySql(const std::string& sql,
		std::map<std::string, int> fileds, std::vector<Json::Value>& results) {
	try {
		std::string statement = sql;
		sql::PreparedStatement *pstmt = con->prepareStatement(
				statement.c_str());
		sql::ResultSet *res = pstmt->executeQuery();
		std::map<std::string, int>::iterator it;
		while (res->next()) {
			Json::Value row;
			for (it = fileds.begin(); it != fileds.end(); ++it) {
				if (it->second == 0) {
					row[it->first] = res->getInt(it->first);
				} else if (it->second == 1) {
					std::stringstream ss;
					std::string tmp;
					ss << res->getString(it->first);
					ss >> tmp;
					row[it->first] = tmp;
				} else if (it->second == 2) {
					row[it->first] = res->getUInt(it->first);
				}
			}
			results.push_back(row);
		}
		delete res;
		delete pstmt;
	} catch (sql::SQLException &e) {
		LY_LOG_ERR("mysql SQLException: " << e.what());
	}
}
void PersistenceServiceMysql::getDataBySql(const std::string& sql,
		std::map<std::string, int>& fileds,
		std::vector<std::map<std::string, std::string> >& results) {
	try {
		std::string statement = sql;
		sql::PreparedStatement *pstmt = con->prepareStatement(
				statement.c_str());
		sql::ResultSet *res = pstmt->executeQuery();
		if (!fileds.empty()) {
			std::map<std::string, int>::iterator it;
			while (res->next()) {
				std::map < std::string, std::string > row;
				for (it = fileds.begin(); it != fileds.end(); ++it) {
					if (it->second == 0) {
						std::stringstream ss;
						int tmp;
						tmp = res->getInt(it->first);
						ss << tmp;
						ss >> row[it->first];
					} else if (it->second == 1) {
						row[it->first] = res->getString(it->first);
					} else if (it->second == 2) {
						std::stringstream ss;
						ss << res->getUInt(it->first);
						ss >> row[it->first];
					}
				}
				results.push_back(row);
			}
		}
		delete res;
		delete pstmt;
	} catch (sql::SQLException &e) {
		LY_LOG_ERR("mysql SQLException: " << e.what());
	}
}
