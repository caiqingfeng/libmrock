#started with '#' are comments

DIRS=common frontend 

OBJS := $(wildcard common/obj/*.o)
OBJS += $(wildcard frontend/obj/*.o)

all: common frontend

common: force_look
	@echo "make common"
	cd common; $(MAKE)
	@echo "build common end"

frontend: force_look
	@echo "make frontend"
	cd frontend; $(MAKE)
	@echo "build frontend end"

install:
	mkdir -p lib
	$(ECHO) $(AR) $(ARFLAGS) lib/libmrock-frontend.a $(OBJS)
	$(AR) $(ARFLAGS) lib/libmrock-frontend.a $(OBJS)
	$(RANLIB) lib/libmrock-frontend.a
	-for d in $(DIRS); do (mkdir -p include/$$d/src; cp $$d/src/*.h include/$$d/src; cp $$d/src/*.hpp include/$$d/src); done

init:
	-rm -rf include/*
	-rm -rf lib/*
	-for d in $(DIRS); do (mkdir -p $$d; rm -r $$d/src; cp -r ../$$d/src $$d); done

clean:
	@echo "clean everything......"
	find . -name "core" -exec rm {} \;
	for d in $(DIRS); do (cd $$d; make clean; cd ..); done
	
finalize:
	-rm -r include/*
	-rm lib/*
	-for d in $(DIRS); do (rm -r $$d/src); done

force_look :
	true

.phony: init clean install
