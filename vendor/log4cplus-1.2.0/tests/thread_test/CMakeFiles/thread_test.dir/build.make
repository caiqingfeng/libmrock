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
include tests/thread_test/CMakeFiles/thread_test.dir/depend.make

# Include the progress variables for this target.
include tests/thread_test/CMakeFiles/thread_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/thread_test/CMakeFiles/thread_test.dir/flags.make

tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o: tests/thread_test/CMakeFiles/thread_test.dir/flags.make
tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o: tests/thread_test/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/thread_test.dir/main.cxx.o -c /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test/main.cxx

tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread_test.dir/main.cxx.i"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test/main.cxx > CMakeFiles/thread_test.dir/main.cxx.i

tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread_test.dir/main.cxx.s"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test/main.cxx -o CMakeFiles/thread_test.dir/main.cxx.s

tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.requires:

.PHONY : tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.requires

tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.provides: tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.requires
	$(MAKE) -f tests/thread_test/CMakeFiles/thread_test.dir/build.make tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.provides.build
.PHONY : tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.provides

tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.provides.build: tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o


# Object files for target thread_test
thread_test_OBJECTS = \
"CMakeFiles/thread_test.dir/main.cxx.o"

# External object files for target thread_test
thread_test_EXTERNAL_OBJECTS =

bin/thread_test: tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o
bin/thread_test: tests/thread_test/CMakeFiles/thread_test.dir/build.make
bin/thread_test: src/liblog4cplus.so.1.2.0
bin/thread_test: /usr/lib/x86_64-linux-gnu/librt.so
bin/thread_test: /usr/lib/x86_64-linux-gnu/libnsl.so
bin/thread_test: tests/thread_test/CMakeFiles/thread_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/thread_test"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/thread_test/CMakeFiles/thread_test.dir/build: bin/thread_test

.PHONY : tests/thread_test/CMakeFiles/thread_test.dir/build

tests/thread_test/CMakeFiles/thread_test.dir/requires: tests/thread_test/CMakeFiles/thread_test.dir/main.cxx.o.requires

.PHONY : tests/thread_test/CMakeFiles/thread_test.dir/requires

tests/thread_test/CMakeFiles/thread_test.dir/clean:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test && $(CMAKE_COMMAND) -P CMakeFiles/thread_test.dir/cmake_clean.cmake
.PHONY : tests/thread_test/CMakeFiles/thread_test.dir/clean

tests/thread_test/CMakeFiles/thread_test.dir/depend:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/thread_test/CMakeFiles/thread_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/thread_test/CMakeFiles/thread_test.dir/depend

