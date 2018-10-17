/*
 * AppdPersistenceService.cpp
 *
 *  Created on: 2013-6-27
 *      Author: caiqingfeng
 */

#include "NetdPersistenceService.h"
//#include "PersistenceServiceMongo.h"
#include "persistence/src/PersistenceServiceRedis.h"
#include "NetdPersistenceServiceMysql.h"
//#include "SerializeHelper.h"

NetdPersistenceService* NetdPersistenceService::_instance = NULL;

NetdPersistenceService::NetdPersistenceService()
{
	// TODO Auto-generated constructor stub
	std::string rails_db_name;
	char* railsDbName = getenv("RAILS_DB_NAME");
	if (railsDbName == NULL) {
		rails_db_name = "rhappyholdem";
	} else {
		rails_db_name = std::string(railsDbName);
	}
	_diskStorage = new NetdPersistenceServiceMysql(rails_db_name);
	_memStorage = _diskStorage;
}

NetdPersistenceService::~NetdPersistenceService() {
	// TODO Auto-generated destructor stub
//	delete _memStorage;
	delete _diskStorage;
}

NetdPersistenceService* NetdPersistenceService::Instance()
{
	// TODO Auto-generated constructor stub
	if (_instance == NULL) {
		_instance = new NetdPersistenceService();
	}
	return _instance;
}

std::string NetdPersistenceService::getKey(const std::string& uid)
{
	return ((NetdPersistenceServiceMysql *)_diskStorage)->getKey(uid);
}
