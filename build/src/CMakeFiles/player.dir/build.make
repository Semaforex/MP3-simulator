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
include src/CMakeFiles/player.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/player.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/player.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/player.dir/flags.make

src/CMakeFiles/player.dir/player.cpp.o: src/CMakeFiles/player.dir/flags.make
src/CMakeFiles/player.dir/player.cpp.o: /home/mparadow/PROI_projekt/CMakeQuickStart/src/player.cpp
src/CMakeFiles/player.dir/player.cpp.o: src/CMakeFiles/player.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mparadow/PROI_projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/player.dir/player.cpp.o"
	cd /home/mparadow/PROI_projekt/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/player.dir/player.cpp.o -MF CMakeFiles/player.dir/player.cpp.o.d -o CMakeFiles/player.dir/player.cpp.o -c /home/mparadow/PROI_projekt/CMakeQuickStart/src/player.cpp

src/CMakeFiles/player.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/player.dir/player.cpp.i"
	cd /home/mparadow/PROI_projekt/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mparadow/PROI_projekt/CMakeQuickStart/src/player.cpp > CMakeFiles/player.dir/player.cpp.i

src/CMakeFiles/player.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/player.dir/player.cpp.s"
	cd /home/mparadow/PROI_projekt/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mparadow/PROI_projekt/CMakeQuickStart/src/player.cpp -o CMakeFiles/player.dir/player.cpp.s

# Object files for target player
player_OBJECTS = \
"CMakeFiles/player.dir/player.cpp.o"

# External object files for target player
player_EXTERNAL_OBJECTS =

src/libplayer.a: src/CMakeFiles/player.dir/player.cpp.o
src/libplayer.a: src/CMakeFiles/player.dir/build.make
src/libplayer.a: src/CMakeFiles/player.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mparadow/PROI_projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libplayer.a"
	cd /home/mparadow/PROI_projekt/build/src && $(CMAKE_COMMAND) -P CMakeFiles/player.dir/cmake_clean_target.cmake
	cd /home/mparadow/PROI_projekt/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/player.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/player.dir/build: src/libplayer.a
.PHONY : src/CMakeFiles/player.dir/build

src/CMakeFiles/player.dir/clean:
	cd /home/mparadow/PROI_projekt/build/src && $(CMAKE_COMMAND) -P CMakeFiles/player.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/player.dir/clean

src/CMakeFiles/player.dir/depend:
	cd /home/mparadow/PROI_projekt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mparadow/PROI_projekt/CMakeQuickStart /home/mparadow/PROI_projekt/CMakeQuickStart/src /home/mparadow/PROI_projekt/build /home/mparadow/PROI_projekt/build/src /home/mparadow/PROI_projekt/build/src/CMakeFiles/player.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/player.dir/depend

