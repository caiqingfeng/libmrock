/*
 * PersistenceServiceMysql_tests.cpp
 *
 *  Created on: 2014年10月17日
 *      Author: luyunstaff001
 */

#include "common/src/my_log.h"

#include <gtest/gtest.h>
#include <json/json.h>
#include "persistence/src/PersistenceServiceMysql.h"

class PersistenceServiceMysql_tests: public ::testing::Test {
public:

	void SetUp() {
		psd = new PersistenceServiceMysql("rpineapple");
		std::string create_test_sql =
				"create database if not exists rpineapple_test DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;";
		std::string create_test_sql1 =
				"create table if not exists users(mobile varchar(20));";
		std::string create_test_sql2 =
				"insert into users (mobile) values ('99999998999');";
		std::map<std::string, int> fileds;
		fileds["mobile"] = 1;
		std::vector < Json::Value > results;
		psd->getJsonDataBySql(create_test_sql, fileds, results);
		psd->getJsonDataBySql(create_test_sql1, fileds, results);
		psd->getJsonDataBySql(create_test_sql2, fileds, results);
	}

	void TearDown() {
		std::string drop_test_sql = "drop table if exists users;";
		std::map<std::string, int> fileds;
		fileds["mobile"] = 1;
		std::vector < Json::Value > results;
		psd->getJsonDataBySql(drop_test_sql, fileds, results);
		delete psd;
	}

public:
	PersistenceServiceMysql* psd;
};

TEST_F(PersistenceServiceMysql_tests, init)
{
	std::vector < Json::Value > results;
	std::map<std::string,int> fileds;
	fileds["mobile"] = 1;
	psd->getJsonDataBySql("select mobile from users;",fileds,results);
//	Json::Value::Members member = data[0].getMemberNames();
//	for(Json::Value::Members::iterator iter = member.begin(); iter != member.end(); ++iter) {
//		ASSERT_EQ(*iter, "last_sign_date");
//	}
}

