#started with '#' are comments

include ../Makefile.inc

SRCP=src
MKDIRS += $(SRCP)
OBJP=obj
MKDIRS += $(OBJP)
LIBP=lib
MKDIRS += $(LIBP)
BIN_PATH=bin
MKDIRS += $(BIN_PATH)
TSTP=test

CURP=$(CURDIR)
#depend dirs
#depend dirs
COMMON=../common

#depend dirs
DPDIRS += $(COMMON)
#depend objs
#DPOBJS=$(COMMON)/obj/holdem.pb.o $(COMMON)/obj/my_log.o
DPOBJS=$(COMMON)/obj/my_log.o
#DPOBJS += ../netd/obj/TimerMsgSender.o
LIBPERSISTENCE=-L$(LIBP) -lpersistence

all: persistence persistence-tests 

CPPSRCS := $(wildcard $(SRCP)/*.cpp)
CPPOBJS := $(patsubst $(SRCP)/%.cpp,$(OBJP)/%.o,$(CPPSRCS)) 
CCSRCS := $(wildcard $(SRCP)/*.cc)
CCOBJS := $(patsubst $(SRCP)/%.cc,$(OBJP)/%.o,$(CCSRCS))
TSTSRCS := $(wildcard $(TSTP)/*.cpp)
TSTOBJS := $(patsubst $(TSTP)/%.cpp,$(OBJP)/%.o,$(TSTSRCS)) 
TIMERP= ../timer
#LIBPOKER= -L../holdem/lib -lholdem -L../poker/lib -lpoker 
#LIBPERSISTENCE= -L$(LIBP) -lpersistence -L$(TIMERP)/lib -ltimer
LIBPERSISTENCE= -L$(LIBP) -lpersistence 
PERSISTENCETGT=../persistence/lib/libpersistence.a

objs: $(CPPOBJS) $(CCOBJS) | $(OBJP)
	@echo "make persistence depend objs"
	-for d in $(DPDIRS); do (cd $$d; make objs);done  
	cd $(CURP)
	#lib
	make holdem

$(CPPOBJS): $(OBJP)/%.o:$(SRCP)/%.cpp | $(OBJP)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(CCOBJS): $(OBJP)/%.o:$(SRCP)/%.cc | $(OBJP)
	$(CC) $(CXXFLAGS) -c $< -o $@
       	
$(TSTOBJS): $(OBJP)/%.o:$(TSTP)/%.cpp | $(OBJP)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(DPOBJS): 
	cd $(COMMON); make

persistence: $(CPPOBJS) $(CCOBJS) $(DPOBJS) | $(LIBP)
	$(ECHO) $(AR) $(ARFLAGS) $(LIBP)/libpersistence.a $(CPPOBJS) $(CCOBJS)
	$(AR) $(ARFLAGS) $(LIBP)/libpersistence.a $(CPPOBJS) $(CCOBJS) 
	$(RANLIB) $(LIBP)/libpersistence.a

$(POKERTGT): 
	cd ../persistence; make

persistence-tests: $(TSTOBJS) $(DPOBJS) persistence $(POKERTGT) | $(BIN_PATH)
	@echo "Link persistence-test begin......"
	$(CC) $(CXXFLAGS) -o $(BIN_PATH)/$@ $(TSTOBJS) $(DPOBJS) $(LIBPERSISTENCE) $(LIB_BASE) $(LIB_MYSQL) $(LIB_BOOST) $(LIB_CRYP) $(LIB_JSON) $(LIB_TEST)
	@echo "Link persistence-tests end......"

test: persistence-tests | $(BIN_PATH)
	@echo "runnning test......"
	#RAILS_ENV=test $(BIN_PATH)/persistence-tests 

clean:
	@echo "Removing persistence linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)
	rm -f $(LIBP)/libpersistence.a

rebuild:
	@echo "run protoc to compile protobuf......"
	make clean all

$(sort $(MKDIRS)) :
	mkdir -p $@
