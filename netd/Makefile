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

#src depend dirs
COMMONP=../common
DPDIRS += $(COMMONP)

#src depend objs and libs
DPCPPSRCS := $(wildcard $(COMMONP)/src/*.cpp)
DPOBJS := $(patsubst %.cpp,$(COMMONP)/obj/%.o,$(notdir $(DPCPPSRCS)))
DPCCSRCS := $(wildcard $(COMMONP)/src/*.cc)
DPOBJS += $(patsubst %.cc,$(COMMONP)/obj/%.o,$(notdir $(DPCCSRCS)))

#test depend objs
TSTDPOBJS := $(DPOBJS)
TSTDPCPPSRCS := $(filter-out $(SRCP)/netd.cpp,$(wildcard $(SRCP)/*.cpp))
TSTDPOBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(TSTDPCPPSRCS)))
TSTDPCCSRCS := $(wildcard $(SRCP)/*.cc)
TSTDPOBJS += $(patsubst %.cc,$(OBJP)/%.o,$(notdir $(TSTDPCCSRCS)))

all: netd netd-tests

objs: $(CPPOBJS) $(CCOBJS)
	@echo "make net_srv depend objs"
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

netd: $(CPPOBJS) $(CCOBJS) $(DPOBJS) | $(BINP)
	@echo "Link netd:begin......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_PERSISTENCE) $(LIB_BASE) $(LIB_CRYP) $(LIB_JSON) $(LIB_MONGO) $(LIB_MYSQL) $(LIB_BOOST)
	@echo "Link netd end......"

netd-tests: $(TSTOBJS) $(TSTDPOBJS) | $(BINP)
	@echo "Link netd-test:begin......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $(TSTOBJS) $(TSTDPOBJS) $(LIB_PERSISTENCE) $(LIB_BASE) $(LIB_TEST) $(LIB_CRYP)  $(LIB_JSON)  $(LIB_MONGO) $(LIB_MYSQL) $(LIB_BOOST)
	@echo "Link netd-test end......"

test: netd-tests | $(BINP)
	@echo "runnning netd-tests......"
	RAILS_ENV=test LUYUN_SERVER_BASE=9000 $(BINP)/netd-tests 

clean:
	@echo "Removing linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)
	rm -f $(BINP)/netd

$(sort $(MKDIRS)) :
	mkdir -p $@
