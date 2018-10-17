/*
 * PersistenceService.cpp
 *
 *  Created on: 2013-6-27
 *      Author: caiqingfeng
 */

#include "PersistenceService.h"
//#include "PersistenceServiceMongo.h"
#include "PersistenceServiceRedis.h"
//#include "SerializeHelper.h"

PersistenceService::PersistenceService()
{
	// TODO Auto-generated constructor stub
}

PersistenceService::~PersistenceService() {
	// TODO Auto-generated destructor stub
}

void PersistenceService::build_collection_names(const std::string &dbname)
{
	//_memStorage->build_collection_names(dbname);
	//_diskStorage->build_collection_names(dbname);
}

