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
include tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/depend.make

# Include the progress variables for this target.
include tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/flags.make

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/flags.make
tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o: tests/customloglevel_test/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/customloglevel_test.dir/main.cxx.o -c /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/main.cxx

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/customloglevel_test.dir/main.cxx.i"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/main.cxx > CMakeFiles/customloglevel_test.dir/main.cxx.i

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/customloglevel_test.dir/main.cxx.s"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/main.cxx -o CMakeFiles/customloglevel_test.dir/main.cxx.s

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.requires:

.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.requires

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.provides: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.requires
	$(MAKE) -f tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/build.make tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.provides.build
.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.provides

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.provides.build: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o


tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/flags.make
tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o: tests/customloglevel_test/func.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/customloglevel_test.dir/func.cxx.o -c /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/func.cxx

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/customloglevel_test.dir/func.cxx.i"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/func.cxx > CMakeFiles/customloglevel_test.dir/func.cxx.i

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/customloglevel_test.dir/func.cxx.s"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/func.cxx -o CMakeFiles/customloglevel_test.dir/func.cxx.s

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.requires:

.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.requires

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.provides: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.requires
	$(MAKE) -f tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/build.make tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.provides.build
.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.provides

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.provides.build: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o


tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/flags.make
tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o: tests/customloglevel_test/customloglevel.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o -c /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/customloglevel.cxx

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/customloglevel_test.dir/customloglevel.cxx.i"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/customloglevel.cxx > CMakeFiles/customloglevel_test.dir/customloglevel.cxx.i

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/customloglevel_test.dir/customloglevel.cxx.s"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/customloglevel.cxx -o CMakeFiles/customloglevel_test.dir/customloglevel.cxx.s

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.requires:

.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.requires

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.provides: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.requires
	$(MAKE) -f tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/build.make tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.provides.build
.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.provides

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.provides.build: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o


# Object files for target customloglevel_test
customloglevel_test_OBJECTS = \
"CMakeFiles/customloglevel_test.dir/main.cxx.o" \
"CMakeFiles/customloglevel_test.dir/func.cxx.o" \
"CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o"

# External object files for target customloglevel_test
customloglevel_test_EXTERNAL_OBJECTS =

bin/customloglevel_test: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o
bin/customloglevel_test: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o
bin/customloglevel_test: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o
bin/customloglevel_test: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/build.make
bin/customloglevel_test: src/liblog4cplus.so.1.2.0
bin/customloglevel_test: /usr/lib/x86_64-linux-gnu/librt.so
bin/customloglevel_test: /usr/lib/x86_64-linux-gnu/libnsl.so
bin/customloglevel_test: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caiqingfeng/vendors/log4cplus-1.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../bin/customloglevel_test"
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/customloglevel_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/build: bin/customloglevel_test

.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/build

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/requires: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/main.cxx.o.requires
tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/requires: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/func.cxx.o.requires
tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/requires: tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/customloglevel.cxx.o.requires

.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/requires

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/clean:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test && $(CMAKE_COMMAND) -P CMakeFiles/customloglevel_test.dir/cmake_clean.cmake
.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/clean

tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/depend:
	cd /home/caiqingfeng/vendors/log4cplus-1.2.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test /home/caiqingfeng/vendors/log4cplus-1.2.0 /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test /home/caiqingfeng/vendors/log4cplus-1.2.0/tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/customloglevel_test/CMakeFiles/customloglevel_test.dir/depend

