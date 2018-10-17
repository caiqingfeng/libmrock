# Install script for directory: /home/caiqingfeng/vendors/log4cplus-1.2.0/src

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/log4cplus" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/generated/log4cplusConfig.cmake"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/generated/log4cplusConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/log4cplus/log4cplusTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/log4cplus/log4cplusTargets.cmake"
         "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/CMakeFiles/Export/lib/cmake/log4cplus/log4cplusTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/log4cplus/log4cplusTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/log4cplus/log4cplusTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/log4cplus" TYPE FILE FILES "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/CMakeFiles/Export/lib/cmake/log4cplus/log4cplusTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/log4cplus" TYPE FILE FILES "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/CMakeFiles/Export/lib/cmake/log4cplus/log4cplusTargets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.1.2.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/liblog4cplus.so.1.2.0"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/liblog4cplus.so.0"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/liblog4cplus.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.1.2.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liblog4cplus.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/appender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/asyncappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/clogger.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/config.hxx"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/configurator.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/consoleappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/fileappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/fstreams.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/hierarchy.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/hierarchylocker.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/layout.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/log4judpappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/logger.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/loggingmacros.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/loglevel.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/mdc.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/ndc.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/nteventlogappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/nullappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/socketappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/streams.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/syslogappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/tchar.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/tracelogger.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/tstring.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/version.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/win32debugappender.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/win32consoleappender.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/boost" TYPE FILE FILES "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/boost/deviceappender.hxx")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/helpers" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/appenderattachableimpl.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/connectorthread.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/fileinfo.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/lockfile.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/loglog.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/logloguser.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/pointer.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/property.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/queue.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/sleep.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/snprintf.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/socket.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/socketbuffer.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/stringhelper.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/thread-config.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/helpers/timehelper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/internal" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/internal/env.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/internal/internal.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/internal/socket.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/spi" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/appenderattachable.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/factory.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/filter.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/loggerfactory.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/loggerimpl.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/loggingevent.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/objectregistry.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/spi/rootlogger.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/thread/impl" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/impl/syncprims-cxx11.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/impl/syncprims-impl.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/impl/syncprims-pthreads.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/impl/syncprims-win32.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/impl/threads-impl.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/impl/tls.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/thread" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/syncprims-pub-impl.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/syncprims.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/thread/threads.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/log4cplus/config" TYPE FILE FILES
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/config/macosx.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/config/win32.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/src/../include/log4cplus/config/windowsh-inc.h"
    "/home/caiqingfeng/vendors/log4cplus-1.2.0/include/log4cplus/config/defines.hxx"
    )
endif()

