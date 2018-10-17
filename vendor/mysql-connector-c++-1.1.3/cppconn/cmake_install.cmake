# Install script for directory: /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppconn" TYPE FILE FILES
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/build_config.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/config.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/connection.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/datatype.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/driver.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/exception.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/metadata.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/parameter_metadata.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/prepared_statement.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/resultset.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/resultset_metadata.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/statement.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/sqlstring.h"
    "/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/cppconn/warning.h"
    )
endif()

