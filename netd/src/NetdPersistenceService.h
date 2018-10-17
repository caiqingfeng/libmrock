/*
 * PersistenceService.h
 *
 *  Created on: 2013-6-27
 *      Author: caiqingfeng
 */

#ifndef NETDPERSISTENCESERVICE_H
#define NETDPERSISTENCESERVICE_H

#include "persistence/src/PersistenceService.h"
#include <vector>
#include <string>

class NetdPersistenceService : public PersistenceService {
private:
	static NetdPersistenceService* _instance;

protected:
	NetdPersistenceService();
	
public:
	static NetdPersistenceService *Instance();
	virtual ~NetdPersistenceService();

public:
	virtual std::string getKey(const std::string& uid);
};

#endif /* SERVERHOLDEMMSGHANDLER_H_ */
