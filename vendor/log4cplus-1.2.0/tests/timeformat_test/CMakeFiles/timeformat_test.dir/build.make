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
include tests/timeformat_test/CMakeFiles/timeformat_test.dir/depend.make

# Include the progress variables for this target.
include tests/timeformat_test/CMakeFiles/timeformat_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/timeformat_test/CMakeFiles/timeformat_test.dir/flags.make

tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o: tests/timeformat_test/CMakeFiles/timeformat_test.dir/flags.make
tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o: tests/timeformat_test/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/timeformat_test.dir/main.cxx.o -c /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test/main.cxx

tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/timeformat_test.dir/main.cxx.i"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test/main.cxx > CMakeFiles/timeformat_test.dir/main.cxx.i

tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/timeformat_test.dir/main.cxx.s"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test/main.cxx -o CMakeFiles/timeformat_test.dir/main.cxx.s

tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.requires:

.PHONY : tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.requires

tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.provides: tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.requires
	$(MAKE) -f tests/timeformat_test/CMakeFiles/timeformat_test.dir/build.make tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.provides.build
.PHONY : tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.provides

tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.provides.build: tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o


# Object files for target timeformat_test
timeformat_test_OBJECTS = \
"CMakeFiles/timeformat_test.dir/main.cxx.o"

# External object files for target timeformat_test
timeformat_test_EXTERNAL_OBJECTS =

bin/timeformat_test: tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o
bin/timeformat_test: tests/timeformat_test/CMakeFiles/timeformat_test.dir/build.make
bin/timeformat_test: src/liblog4cplus.so.1.2.0
bin/timeformat_test: /usr/lib/x86_64-linux-gnu/librt.so
bin/timeformat_test: /usr/lib/x86_64-linux-gnu/libnsl.so
bin/timeformat_test: tests/timeformat_test/CMakeFiles/timeformat_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/timeformat_test"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timeformat_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/timeformat_test/CMakeFiles/timeformat_test.dir/build: bin/timeformat_test

.PHONY : tests/timeformat_test/CMakeFiles/timeformat_test.dir/build

tests/timeformat_test/CMakeFiles/timeformat_test.dir/requires: tests/timeformat_test/CMakeFiles/timeformat_test.dir/main.cxx.o.requires

.PHONY : tests/timeformat_test/CMakeFiles/timeformat_test.dir/requires

tests/timeformat_test/CMakeFiles/timeformat_test.dir/clean:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test && $(CMAKE_COMMAND) -P CMakeFiles/timeformat_test.dir/cmake_clean.cmake
.PHONY : tests/timeformat_test/CMakeFiles/timeformat_test.dir/clean

tests/timeformat_test/CMakeFiles/timeformat_test.dir/depend:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/timeformat_test/CMakeFiles/timeformat_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/timeformat_test/CMakeFiles/timeformat_test.dir/depend

