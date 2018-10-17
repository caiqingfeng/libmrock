#started with '#' are comments

include ../Makefile.inc

SRCP=src
OBJP=obj
TSTP=test
MKDIRS += $(OBJP)
LIBP=lib
MKDIRS += $(LIBP)
BINP=bin
MKDIRS += $(BINP)

CURP=$(CURDIR)

#src
CPPSRCS := $(wildcard $(SRCP)/*.cpp)
CPPOBJS := $(patsubst $(SRCP)/%.cpp,$(OBJP)/%.o,$(CPPSRCS))
CCSRCS := $(wildcard $(SRCP)/*.cc)
CCOBJS := $(patsubst $(SRCP)/%.cc,$(OBJP)/%.o,$(CCSRCS))
TSTSRCS := $(wildcard $(TSTP)/*.cpp)
TSTOBJS := $(patsubst $(TSTP)/%.cpp,$(OBJP)/%.o,$(TSTSRCS))

DEPFILES := $(patsubst %.cpp,$(OBJP)/%.d,$(CPPSRCS))
-include $(DEPFILES)
#LIBEV=-lev

#src depend dirs
COMMONP=../common
TIMERP=../timer
DPDIRS += $(COMMONP)
DPDIRS += $(TIMERP)

#src depend objs and libs
DPCPPSRCS := $(wildcard $(COMMONP)/src/*.cpp)
DPOBJS := $(patsubst %.cpp,$(COMMONP)/obj/%.o,$(notdir $(DPCPPSRCS)))
DPCCSRCS := $(wildcard $(COMMONP)/src/*.cc)
DPOBJS += $(patsubst %.cc,$(COMMONP)/obj/%.o,$(notdir $(DPCCSRCS)))

#src depend objs and libs
TIMERCPPSRCS := $(wildcard $(TIMERP)/src/*.cpp)
TIMEROBJS := $(patsubst %.cpp,$(TIMERP)/obj/%.o,$(notdir $(TIMERCPPSRCS)))
TIMERCCSRCS := $(wildcard $(TIMERP)/src/*.cc)
TIMEROBJS += $(patsubst %.cc,$(TIMERP)/obj/%.o,$(notdir $(TIMERCCSRCS)))

STARTERSRCS := $(filter-out $(SRCP)/timerc.cpp $(SRCP)/concrete.cpp, $(wildcard $(SRCP)/*.cpp))
STARTEROBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(STARTERSRCS)))
TIMERCSRCS := $(filter-out $(SRCP)/starter.cpp $(SRCP)/concrete.cpp, $(wildcard $(SRCP)/*.cpp))
TIMERCOBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(TIMERCSRCS)))
CONCRETESRCS := $(SRCP)/concrete.cpp $(SRCP)/LYSimpleTimerMgr.cpp
CONCRETEOBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(CONCRETESRCS)))
#test depend objs
TSTDPOBJS := $(DPOBJS)
TSTDPCPPSRCS := $(filter-out $(SRCP)/starter.cpp $(SRCP)/timerc.cpp $(SRCP)/concrete.cpp, $(wildcard $(SRCP)/*.cpp))
TSTDPOBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(TSTDPCPPSRCS)))
TSTDPCCSRCS := $(wildcard $(SRCP)/*.cc)
TSTDPOBJS += $(patsubst %.cc,$(OBJP)/%.o,$(notdir $(TSTDPCCSRCS)))

#all: starter starter-tests timerc concrete
all: timerc concrete


objs: $(CPPOBJS) $(CCOBJS)
	@echo "make starter depend objs"
	-for d in $(DPDIRS); do (cd $$d; $(MAKE) objs || exit "$$?");done  
	cd $(CURP)

$(CPPOBJS): $(OBJP)/%.o:$(SRCP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CCOBJS): $(OBJP)/%.o:$(SRCP)/%.cc | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -o $@
       	
$(TSTOBJS): $(OBJP)/%.o:$(TSTP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DPOBJS): 
	cd $(COMMONP); make

$(TIMEROBJS): 
	cd $(TIMERP); make

starter: $(STARTEROBJS) $(TIMEROBJS) $(DPOBJS) | $(BINP)
	@echo "Link starter......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_PERSISTENCE) $(LIB_BASE) $(LIBEV) $(LIB_CRYP) $(LIB_JSON) $(LIB_MONGO) $(LIB_MYSQL) $(LIB_BOOST)
	@echo "Link starter end......"

concrete: $(CONCRETEOBJS) $(TIMEROBJS) $(DPOBJS) | $(BINP)
	@echo "Link concrete......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_BASE) $(LIB_CRYP) $(LIB_BOOST)
	@echo "Link concrete end......"

timerc: $(TIMERCOBJS) $(TIMEROBJS) $(DPOBJS) | $(BINP)
	@echo "Link timerc......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_PERSISTENCE) $(LIB_BASE) $(LIBEV) $(LIB_CRYP) $(LIB_JSON) $(LIB_MONGO) $(LIB_MYSQL) $(LIB_BOOST)
	@echo "Link timerc end......"

starter-tests: $(TSTOBJS) $(TSTDPOBJS) $(TIMEROBJS) | $(BINP)
	@echo "Link starter-test:begin......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_PERSISTENCE) $(LIB_BASE) $(LIBEV) $(LIB_TEST) $(LIB_CRYP)  $(LIB_JSON)  $(LIB_MONGO) $(LIB_MYSQL) $(LIB_BOOST)
	@echo "Link starter-test end......"

test: starter-tests | $(BINP)
	@echo "runnning starter-tests......"
	RAILS_ENV=test LUYUN_SERVER_BASE=9000 $(BINP)/starter-tests 

clean:
	@echo "Removing linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)
	rm -f $(TSTOBJS)
	rm -f $(BINP)/starter

$(sort $(MKDIRS)) :
	mkdir -p $@
