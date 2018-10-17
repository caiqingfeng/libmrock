#started with '#' are comments
include ../Makefile.inc

SRCP=src
TSTP=test
OBJP=obj
MKDIRS += $(OBJP)
LIBP=lib
MKDIRS += $(LIBP)
BINP=bin
MKDIRS += $(BINP)

CURP=$(CURDIR)

#src
CPPSRCS := $(wildcard $(SRCP)/*.cpp)
CPPOBJS := $(patsubst $(SRCP)/%.cpp,$(OBJP)/%.o,$(CPPSRCS)) 
TSTSRCS := $(wildcard $(TSTP)/*.cpp)
TSTOBJS := $(patsubst $(TSTP)/%.cpp,$(OBJP)/%.o,$(TSTSRCS))

DEPFILES := $(patsubst %.cpp,$(OBJP)/%.d,$(CPPSRCS))
-include $(DEPFILES)

#src depend dirs
COMMONP=../common
DPDIRS += $(COMMONP)
TIMERP := ../timer
DPDIRS += $(TIMERP)
PERSISTENCEP := ../persistence
DPDIRS += $(PERSISTENCEP)

#src depend objs and libs
DPCPPSRCS := $(wildcard $(COMMONP)/src/*.cpp)
DPOBJS := $(patsubst %.cpp,$(COMMONP)/obj/%.o,$(notdir $(DPCPPSRCS)))
DPCCSRCS := $(wildcard $(COMMONP)/src/*.cc)
DPOBJS += $(patsubst %.cc,$(COMMONP)/obj/%.o,$(notdir $(DPCCSRCS)))
#DPLIBS := $(EXAMP)/lib/libhandler.a
#timerp depend objs and libs
#src depend objs and libs
TIMERCPPSRCS := $(wildcard $(TIMERP)/src/*.cpp)
TIMEROBJS := $(patsubst %.cpp,$(TIMERP)/obj/%.o,$(notdir $(TIMERCPPSRCS)))
TIMERCCSRCS := $(wildcard $(TIMERP)/src/*.cc)
TIMEROBJS += $(patsubst %.cc,$(TIMERP)/obj/%.o,$(notdir $(TIMERCCSRCS)))
DPOBJS += $(TIMEROBJS)

PERSISTENCECPPSRCS := $(wildcard $(PERSISTENCEP)/src/*.cpp)
PERSISTENCEOBJS := $(patsubst %.cpp,$(PERSISTENCEP)/obj/%.o,$(notdir $(PERSISTENCECPPSRCS)))
PERSISTENCECCSRCS := $(wildcard $(PERSISTENCEP)/src/*.cc)
PERSISTENCEOBJS += $(patsubst %.cc,$(PERSISTENCEP)/obj/%.o,$(notdir $(PERSISTENCECCSRCS)))
DPOBJS += $(PERSISTENCEOBJS)

#test depend objs
TSTDPOBJS=$(DPOBJS)
TSTDPSRCS=$(filter-out $(SRCP)/appd.cpp,$(wildcard $(SRCP)/*.cpp))
TSTDPOBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(TSTDPSRCS)))
TSTDPCCSRCS := $(wildcard $(SRCP)/*.cc)
TSTDPOBJS += $(patsubst %.cc,$(OBJP)/%.o,$(notdir $(TSTDPCCSRCS)))
TSTDPOBJS += $(TIMEROBJS)

all: backend backend-tests

objs: $(CPPOBJS) $(CCOBJS) $(TSTOBJS)
	@echo "make backend depend objs"
	-for d in $(DPDIRS); do (cd $$d; $(MAKE) objs || exit "$$?");done
	cd $(CURP)

$(CPPOBJS): $(OBJP)/%.o:$(SRCP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(CCOBJS): $(OBJP)/%.o:$(SRCP)/%.cc | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(TSTOBJS): $(OBJP)/%.o:$(TSTP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

$(DPOBJS): $(DPSRCS)
	cd $(COMMONP); make

backend: $(CCOBJS) $(CPPOBJS) $(DPOBJS) $(DPLIBS) | $(LIBP)
	@echo "Link backend begin......"
	$(ECHO) $(AR) $(ARFLAGS) $(LIBP)/libmrock-backend.a $(CPPOBJS) $(CCOBJS) $(DPOBJS)
	$(AR) $(ARFLAGS) $(LIBP)/libmrock-backend.a $(CPPOBJS) $(CCOBJS)  $(DPOBJS)
	$(RANLIB) $(LIBP)/libmrock-backend.a
	@echo "Link backend end......"

backend-tests: $(TSTOBJS) $(TSTDPOBJS) $(DPLIBS) | $(BINP)
	@echo "Link backend-tests: begin......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_SERVER) $(LIB_BASE) $(LIB_REDIS) $(LIB_MYSQL) $(LIB_BOOST) $(LIB_CRYP) $(LIB_JSON) $(LIB_TEST)
	@echo "Link backend-tests end......"

test: backend-tests | $(BINP)
	@echo "runnning backend-tests......"
	RAILS_ENV=test $(BINP)/backend-tests

clean:
	@echo "Removing linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)
	rm -f $(TSTOBJS)
	rm -f $(BINP)/*

.phony: clean

$(sort $(MKDIRS)):
	mkdir -p $@
