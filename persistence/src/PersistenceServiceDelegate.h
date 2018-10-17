/*
 * PersistenceService.h
 *
 *  Created on: 2013-6-27
 *      Author: caiqingfeng
 */

#ifndef PERSISTENCESERVICEDELEGATE_H
#define PERSISTENCESERVICEDELEGATE_H
#include <string>

class PersistenceServiceDelegate {
public:
	std::string railsEnv;
	std::string dbName;

public:
	PersistenceServiceDelegate(const std::string& db_name);
	
public:
	virtual ~PersistenceServiceDelegate();

};

#endif /* PERSISTENCESERVICEDELEGATE_H */
