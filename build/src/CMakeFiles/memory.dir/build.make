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

# Include any dependencies generated for this target.
include src/CMakeFiles/memory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/memory.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/memory.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/memory.dir/flags.make

src/CMakeFiles/memory.dir/memory.cpp.o: src/CMakeFiles/memory.dir/flags.make
src/CMakeFiles/memory.dir/memory.cpp.o: /home/mparadow/PROI_projekt/CMakeQuickStart/src/memory.cpp
src/CMakeFiles/memory.dir/memory.cpp.o: src/CMakeFiles/memory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mparadow/PROI_projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/memory.dir/memory.cpp.o"
	cd /home/mparadow/PROI_projekt/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/memory.dir/memory.cpp.o -MF CMakeFiles/memory.dir/memory.cpp.o.d -o CMakeFiles/memory.dir/memory.cpp.o -c /home/mparadow/PROI_projekt/CMakeQuickStart/src/memory.cpp

src/CMakeFiles/memory.dir/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memory.dir/memory.cpp.i"
	cd /home/mparadow/PROI_projekt/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mparadow/PROI_projekt/CMakeQuickStart/src/memory.cpp > CMakeFiles/memory.dir/memory.cpp.i

src/CMakeFiles/memory.dir/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memory.dir/memory.cpp.s"
	cd /home/mparadow/PROI_projekt/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mparadow/PROI_projekt/CMakeQuickStart/src/memory.cpp -o CMakeFiles/memory.dir/memory.cpp.s

# Object files for target memory
memory_OBJECTS = \
"CMakeFiles/memory.dir/memory.cpp.o"

# External object files for target memory
memory_EXTERNAL_OBJECTS =

src/libmemory.a: src/CMakeFiles/memory.dir/memory.cpp.o
src/libmemory.a: src/CMakeFiles/memory.dir/build.make
src/libmemory.a: src/CMakeFiles/memory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mparadow/PROI_projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmemory.a"
	cd /home/mparadow/PROI_projekt/build/src && $(CMAKE_COMMAND) -P CMakeFiles/memory.dir/cmake_clean_target.cmake
	cd /home/mparadow/PROI_projekt/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/memory.dir/build: src/libmemory.a
.PHONY : src/CMakeFiles/memory.dir/build

src/CMakeFiles/memory.dir/clean:
	cd /home/mparadow/PROI_projekt/build/src && $(CMAKE_COMMAND) -P CMakeFiles/memory.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/memory.dir/clean

src/CMakeFiles/memory.dir/depend:
	cd /home/mparadow/PROI_projekt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mparadow/PROI_projekt/CMakeQuickStart /home/mparadow/PROI_projekt/CMakeQuickStart/src /home/mparadow/PROI_projekt/build /home/mparadow/PROI_projekt/build/src /home/mparadow/PROI_projekt/build/src/CMakeFiles/memory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/memory.dir/depend
