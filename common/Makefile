#started with '#' are comments
include ../Makefile.inc

PROTOP=proto
SRCP=src
TSTP=test
BINP=bin
MKDIRS += $(BINP)
OBJP=obj
MKDIRS += $(OBJP)
LIBP=lib
MKDIRS += $(LIBP)

PROTOSRCS := $(wildcard $(PROTOP)/*.proto)
PROTOOBJS := $(patsubst $(PROTOP)/%.proto,$(SRCP)/%.pb.cc,$(PROTOSRCS))
CPPSRCS := $(wildcard $(SRCP)/*.cpp)
CPPOBJS := $(patsubst $(SRCP)/%.cpp,$(OBJP)/%.o,$(CPPSRCS)) 
CCSRCS := $(wildcard $(SRCP)/*.cc)
CCOBJS := $(patsubst $(SRCP)/%.cc,$(OBJP)/%.o,$(CCSRCS))

TSTSRCS := $(wildcard $(TSTP)/*.cpp)
TSTOBJS := $(patsubst $(TSTP)/%.cpp,$(OBJP)/%.o,$(TSTSRCS))

#test depend objs
TSTDPOBJS=$(DPOBJS)
TSTDPSRCS=$(filter-out $(SRCP)/feedmain.cpp,$(wildcard $(SRCP)/*.cpp))
TSTDPOBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(TSTDPSRCS)))
TSTDPCCSRCS := $(wildcard $(SRCP)/*.cc)
TSTDPOBJS += $(patsubst %.cc,$(OBJP)/%.o,$(notdir $(TSTDPCCSRCS)))

all: $(PROTOOBJS) result 
test: common-tests | $(BINP)
	@echo "runnning common-tests......"
	RAILS_ENV=test $(BINP)/common-tests

$(PROTOOBJS): $(SRCP)/%.pb.cc:$(PROTOP)/%.proto
	@echo "compile proto begin......"
	protoc -I./proto --cpp_out=./src $<
	@echo "compile proto end......"

$(CPPOBJS): $(OBJP)/%.o:$(SRCP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CCOBJS): $(OBJP)/%.o:$(SRCP)/%.cc | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -o $@
       	
$(TSTOBJS): $(OBJP)/%.o:$(TSTP)/%.cpp | $(OBJP)
	$(CXX) $(CXXFLAGS) -c $< -MMD -o $@

objs: $(CPPOBJS) $(CCOBJS) 
	@echo "common"
	
result: objs
	@echo "common"

common-tests: $(TSTOBJS) $(TSTDPOBJS) $(DPLIBS) | $(BINP)
	@echo "common test"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_SERVER) $(LIB_BASE) $(LIB_REDIS) $(LIB_MYSQL) $(LIB_BOOST) $(LIB_CRYP) $(LIB_JSON) $(LIB_TEST)
	@echo "Link common-tests end......"


clean:
	@echo "Removing linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)

$(sort $(MKDIRS)) :
	mkdir -p $@
