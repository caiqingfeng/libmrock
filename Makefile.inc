#started with '#' are comments

#LIB_BASE = -L../../vendor/zeromq-4.0.3/lib -lzmq -lprotobuf -llog4cplus
LIB_BASE = -L../vendor/zeromq-4.0.4/lib -L/usr/local/lib -lzmq -lprotobuf -llog4cplus
LIB_PERSISTENCE = -L$(LIBMROCK)/persistence/lib -lpersistence
LIB_SERVER = -L$(LIBMROCK)/backend/lib -lmrock-backend $(LIB_PERSISTENCE) -lstdc++
LIB_FRONTEND = -L$(LIBMROCK)/frontend/lib -lmrock-frontend
#LIB_MYSQL = -lmysqlclient
LIB_MYSQL = -lmysqlcppconn
LIB_REDIS = -lhiredis
#LIB_MONGO = -lmongoclient
#2014.09.24修改：当Ubuntu版本升级14.04时，gtest需要链接-lpthread
LIB_GTEST = -lgtest -lpthread
LIB_GMOCK = -lgmock -lpthread
LIB_TEST = $(LIB_GTEST)
#LIB_CRYP = -L/usr/lib/ -lcryptopp
LIB_CRYP =  -lcryptopp
LIB_JSON = -ljson_linux-gcc-4.x_libmt
LIB_BOOST = -lboost_thread -lboost_regex -lboost_system -lboost_filesystem -lboost_program_options -lboost_date_time

CPP_FLAGS_32 := -DBIT32
CPP_FLAGS_64 := -DBIT64
ARCH := $(shell getconf LONG_BIT)
#CXXFLAGS=$(CPP_FLAGS_$(ARCH)) -std=c++0x -Wall -Wno-unused-function -g

CXXFLAGS = $(CPP_FLAGS_$(ARCH)) -O2 -g -Wall -fmessage-length=0 -Wno-unused-function 
CXXFLAGS += -I.. -I../vendor/zeromq-4.0.4/include -I../ -I../../ -I$(LIBMROCK) -I/usr/local/include/ -I/usr/include/ 

AR  = ar
ARFLAGS = rv
RANLIB  = ranlib

CC=g++
CXX=g++
