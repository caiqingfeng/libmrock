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
CMAKE_SOURCE_DIR = /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3

# Include any dependencies generated for this target.
include examples/CMakeFiles/exceptions.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/exceptions.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/exceptions.dir/flags.make

examples/CMakeFiles/exceptions.dir/exceptions.cpp.o: examples/CMakeFiles/exceptions.dir/flags.make
examples/CMakeFiles/exceptions.dir/exceptions.cpp.o: examples/exceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/exceptions.dir/exceptions.cpp.o"
	cd /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exceptions.dir/exceptions.cpp.o -c /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples/exceptions.cpp

examples/CMakeFiles/exceptions.dir/exceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exceptions.dir/exceptions.cpp.i"
	cd /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples/exceptions.cpp > CMakeFiles/exceptions.dir/exceptions.cpp.i

examples/CMakeFiles/exceptions.dir/exceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exceptions.dir/exceptions.cpp.s"
	cd /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples/exceptions.cpp -o CMakeFiles/exceptions.dir/exceptions.cpp.s

examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.requires:

.PHONY : examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.requires

examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.provides: examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/exceptions.dir/build.make examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.provides.build
.PHONY : examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.provides

examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.provides.build: examples/CMakeFiles/exceptions.dir/exceptions.cpp.o


# Object files for target exceptions
exceptions_OBJECTS = \
"CMakeFiles/exceptions.dir/exceptions.cpp.o"

# External object files for target exceptions
exceptions_EXTERNAL_OBJECTS =

examples/exceptions: examples/CMakeFiles/exceptions.dir/exceptions.cpp.o
examples/exceptions: examples/CMakeFiles/exceptions.dir/build.make
examples/exceptions: driver/libmysqlcppconn-static.a
examples/exceptions: examples/CMakeFiles/exceptions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exceptions"
	cd /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exceptions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/exceptions.dir/build: examples/exceptions

.PHONY : examples/CMakeFiles/exceptions.dir/build

examples/CMakeFiles/exceptions.dir/requires: examples/CMakeFiles/exceptions.dir/exceptions.cpp.o.requires

.PHONY : examples/CMakeFiles/exceptions.dir/requires

examples/CMakeFiles/exceptions.dir/clean:
	cd /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples && $(CMAKE_COMMAND) -P CMakeFiles/exceptions.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/exceptions.dir/clean

examples/CMakeFiles/exceptions.dir/depend:
	cd /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3 /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3 /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples /home/caiqingfeng/workspace/libmrock/vendor/mysql-connector-c++-1.1.3/examples/CMakeFiles/exceptions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/exceptions.dir/depend
