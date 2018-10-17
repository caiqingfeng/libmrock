#include "PersistenceServiceDelegate.h"
#include <stdlib.h>
#include <string.h>

PersistenceServiceDelegate::PersistenceServiceDelegate(
		const std::string& db_name) {
	// TODO Auto-generated constructor stub
	char *rails_env = getenv("RAILS_ENV");
	if (rails_env != NULL) {
		railsEnv = std::string(rails_env);
	} else {
		railsEnv = "test";
	}
	dbName = db_name;
}

PersistenceServiceDelegate::~PersistenceServiceDelegate() {
}

