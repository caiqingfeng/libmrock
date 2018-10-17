/*
 * PersistenceService.h
 *
 *  Created on: 2013-6-27
 *      Author: caiqingfeng
 */

#ifndef PERSISTENCESERVICE_H
#define PERSISTENCESERVICE_H

#include <string>
#include "PersistenceServiceDelegate.h"

/*
 * 实际上这个类并没有提供太多的功能，只是把Redis/Mysql/Mongo的基本功能封装了一下
 */
class PersistenceService {
public:
	PersistenceServiceDelegate *_memStorage; //Memory Storage
	PersistenceServiceDelegate *_diskStorage; //Disk Storage, can be same!!!

public:
	PersistenceService();
	virtual ~PersistenceService();
	
public:
	virtual void build_collection_names(const std::string &dbname);

public:

	void dropAllCollections(const std::string dbname="test");
};

#endif /* PERSISTENCESERVICE_H */
