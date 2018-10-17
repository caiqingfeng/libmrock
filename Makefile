#started with '#' are comments

DIRS=common persistence backend frontend netd concrete
INSTALL_DIRS=netd 
CC=gcc
CXX=g++

#all: src test 
all: common persistence backend frontend netd concrete
test: common-tests persistence-tests backend-tests frontend-tests netd-tests concrete-tests

common: force_look
	@echo "make common"
	cd common; $(MAKE)
	@echo "build common end"

common-tests: force_look
	@echo "make common test"
	cd common; $(MAKE) test
	@echo "test common end"

netd: force_look
	@echo "make netd"
	cd netd; $(MAKE)
	@echo "build netd end"

netd-tests: force_look
	cd netd; $(MAKE) test

concrete: force_look
	@echo "make concrete"
	cd concrete; $(MAKE)
	@echo "build concrete end"

concrete-tests: force_look
	cd concrete; $(MAKE) test

persistence: force_look
	@echo "make persistence"
	cd persistence; $(MAKE)
	@echo "build persistence end"

persistence-tests: force_look
	@echo "make persistence"
	cd persistence; $(MAKE) test
	@echo "test persistence end"

persistence-tests: force_look
	@echo "make persistence"
	cd persistence; $(MAKE) test
	@echo "test persistence end"

backend: force_look
	@echo "make backend"
	cd backend; $(MAKE)
	@echo "build backend end"

backend-tests: force_look
	cd backend; $(MAKE) test

frontend: force_look
	@echo "make frontend"
	cd frontend; $(MAKE)
	@echo "build frontend end"

frontend-tests: force_look
	cd frontend; $(MAKE) test
	
android: force_look
	@echo "make android"
	cd android; ./build.sh
	@echo "build android end"

ios: force_look
	@echo "make ios"
	cd ios; ./build.sh
	@echo "build ios end"

install:
	-for d in $(INSTALL_DIRS); do (cp $$d/bin/* bin); done

clean:
	@echo "clean everything......"
	rm -f bin/*
	find . -name "core" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "libmrock*" -exec rm {} \;
	-for d in $(DIRS); do (cd $$d; make clean; cd ..); done

force_look :
	true

.phony: clean
