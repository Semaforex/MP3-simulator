# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mparadow/PROI_projekt/CMakeQuickStart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mparadow/PROI_projekt/build

# Utility rule file for NightlyTest.

# Include any custom commands dependencies for this target.
include test/CMakeFiles/NightlyTest.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/NightlyTest.dir/progress.make

test/CMakeFiles/NightlyTest:
	cd /home/mparadow/PROI_projekt/build/test && /usr/bin/ctest -D NightlyTest

NightlyTest: test/CMakeFiles/NightlyTest
NightlyTest: test/CMakeFiles/NightlyTest.dir/build.make
.PHONY : NightlyTest

# Rule to build all files generated by this target.
test/CMakeFiles/NightlyTest.dir/build: NightlyTest
.PHONY : test/CMakeFiles/NightlyTest.dir/build

test/CMakeFiles/NightlyTest.dir/clean:
	cd /home/mparadow/PROI_projekt/build/test && $(CMAKE_COMMAND) -P CMakeFiles/NightlyTest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/NightlyTest.dir/clean

test/CMakeFiles/NightlyTest.dir/depend:
	cd /home/mparadow/PROI_projekt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mparadow/PROI_projekt/CMakeQuickStart /home/mparadow/PROI_projekt/CMakeQuickStart/test /home/mparadow/PROI_projekt/build /home/mparadow/PROI_projekt/build/test /home/mparadow/PROI_projekt/build/test/CMakeFiles/NightlyTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/NightlyTest.dir/depend

