# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caiqingfeng/vendors/log4cplus-1.2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caiqingfeng/vendors/log4cplus-1.2.0

# Include any dependencies generated for this target.
include simpleserver/CMakeFiles/loggingserver.dir/depend.make

# Include the progress variables for this target.
include simpleserver/CMakeFiles/loggingserver.dir/progress.make

# Include the compile flags for this target's objects.
include simpleserver/CMakeFiles/loggingserver.dir/flags.make

simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o: simpleserver/CMakeFiles/loggingserver.dir/flags.make
simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o: simpleserver/loggingserver.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/loggingserver.dir/loggingserver.cxx.o -c /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver/loggingserver.cxx

simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/loggingserver.dir/loggingserver.cxx.i"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver/loggingserver.cxx > CMakeFiles/loggingserver.dir/loggingserver.cxx.i

simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/loggingserver.dir/loggingserver.cxx.s"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver/loggingserver.cxx -o CMakeFiles/loggingserver.dir/loggingserver.cxx.s

simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.requires:

.PHONY : simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.requires

simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.provides: simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.requires
	$(MAKE) -f simpleserver/CMakeFiles/loggingserver.dir/build.make simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.provides.build
.PHONY : simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.provides

simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.provides.build: simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o


# Object files for target loggingserver
loggingserver_OBJECTS = \
"CMakeFiles/loggingserver.dir/loggingserver.cxx.o"

# External object files for target loggingserver
loggingserver_EXTERNAL_OBJECTS =

bin/loggingserver: simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o
bin/loggingserver: simpleserver/CMakeFiles/loggingserver.dir/build.make
bin/loggingserver: src/liblog4cplus.so.1.2.0
bin/loggingserver: /usr/lib/x86_64-linux-gnu/librt.so
bin/loggingserver: /usr/lib/x86_64-linux-gnu/libnsl.so
bin/loggingserver: simpleserver/CMakeFiles/loggingserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/loggingserver"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/loggingserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
simpleserver/CMakeFiles/loggingserver.dir/build: bin/loggingserver

.PHONY : simpleserver/CMakeFiles/loggingserver.dir/build

simpleserver/CMakeFiles/loggingserver.dir/requires: simpleserver/CMakeFiles/loggingserver.dir/loggingserver.cxx.o.requires

.PHONY : simpleserver/CMakeFiles/loggingserver.dir/requires

simpleserver/CMakeFiles/loggingserver.dir/clean:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver && $(CMAKE_COMMAND) -P CMakeFiles/loggingserver.dir/cmake_clean.cmake
.PHONY : simpleserver/CMakeFiles/loggingserver.dir/clean

simpleserver/CMakeFiles/loggingserver.dir/depend:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver /home/caiqingfeng/vendors/log4cplus-1.2.0/simpleserver/CMakeFiles/loggingserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simpleserver/CMakeFiles/loggingserver.dir/depend
