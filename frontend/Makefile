#started with '#' are comments
include ../Makefile.inc

PROTOP=proto
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
PROTOSRCS := $(wildcard $(PROTOP)/*.proto)
PROTOOBJS := $(patsubst $(PROTOP)/%.proto,$(SRCP)/%.pb.cc,$(PROTOSRCS))
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
TSTDPCPPSRCS := $(wildcard $(SRCP)/*.cpp)
TSTDPOBJS += $(patsubst %.cpp,$(OBJP)/%.o,$(notdir $(TSTDPCPPSRCS)))
TSTDPCCSRCS := $(wildcard $(SRCP)/*.cc)
TSTDPOBJS += $(patsubst %.cc,$(OBJP)/%.o,$(notdir $(TSTDPCCSRCS)))

all: frontend frontend-tests

objs: $(CPPOBJS) $(CCOBJS) $(TSTOBJS)
	@echo "make frontend depend objs"
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

frontend: $(CCOBJS) $(CPPOBJS) $(DPOBJS) | $(LIBP)
	$(ECHO) $(AR) $(ARFLAGS) $(OBJP)/libmrock-frontend.a $(CPPOBJS) $(CCOBJS) $(DPOBJS)
	$(AR) $(ARFLAGS) $(LIBP)/libmrock-frontend.a $(CPPOBJS) $(CCOBJS) $(DPOBJS)
	$(RANLIB) $(LIBP)/libmrock-frontend.a

frontend-tests: $(TSTOBJS) $(TSTDPOBJS) $(DPLIBS) | $(BINP)
	@echo "Link frontend-tests begin......"
	$(CXX) $(CXXFLAGS) -o $(BINP)/$@ $^ $(LIB_BASE) $(LIB_TEST) $(LIB_BOOST) $(LIB_CRYP)
	@echo "Link frontend-test end......"

test: frontend-tests | $(BINP)
	@echo "runnning frontend-tests......"
	RAILS_ENV=test $(BINP)/frontend-tests 

clean:
	@echo "Removing linked and compiled files......"
	rm -f $(CPPOBJS)
	rm -f $(CCOBJS)
	rm -f $(TSTOBJS)
	rm -f $(LIBP)/libhandler.a
	rm -f $(BINP)/handler-tests

.phony: clean

$(sort $(MKDIRS)) :
	mkdir -p $@
