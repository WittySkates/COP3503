# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/connor/CLionProjects/ProjectOfDeath

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjectOfDeath.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjectOfDeath.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectOfDeath.dir/flags.make

CMakeFiles/ProjectOfDeath.dir/main.cpp.o: CMakeFiles/ProjectOfDeath.dir/flags.make
CMakeFiles/ProjectOfDeath.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjectOfDeath.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectOfDeath.dir/main.cpp.o -c /Users/connor/CLionProjects/ProjectOfDeath/main.cpp

CMakeFiles/ProjectOfDeath.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectOfDeath.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connor/CLionProjects/ProjectOfDeath/main.cpp > CMakeFiles/ProjectOfDeath.dir/main.cpp.i

CMakeFiles/ProjectOfDeath.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectOfDeath.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connor/CLionProjects/ProjectOfDeath/main.cpp -o CMakeFiles/ProjectOfDeath.dir/main.cpp.s

CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.o: CMakeFiles/ProjectOfDeath.dir/flags.make
CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.o: ../LinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.o -c /Users/connor/CLionProjects/ProjectOfDeath/LinkedList.cpp

CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connor/CLionProjects/ProjectOfDeath/LinkedList.cpp > CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.i

CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connor/CLionProjects/ProjectOfDeath/LinkedList.cpp -o CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.s

# Object files for target ProjectOfDeath
ProjectOfDeath_OBJECTS = \
"CMakeFiles/ProjectOfDeath.dir/main.cpp.o" \
"CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.o"

# External object files for target ProjectOfDeath
ProjectOfDeath_EXTERNAL_OBJECTS =

ProjectOfDeath: CMakeFiles/ProjectOfDeath.dir/main.cpp.o
ProjectOfDeath: CMakeFiles/ProjectOfDeath.dir/LinkedList.cpp.o
ProjectOfDeath: CMakeFiles/ProjectOfDeath.dir/build.make
ProjectOfDeath: CMakeFiles/ProjectOfDeath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ProjectOfDeath"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjectOfDeath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectOfDeath.dir/build: ProjectOfDeath

.PHONY : CMakeFiles/ProjectOfDeath.dir/build

CMakeFiles/ProjectOfDeath.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjectOfDeath.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjectOfDeath.dir/clean

CMakeFiles/ProjectOfDeath.dir/depend:
	cd /Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/connor/CLionProjects/ProjectOfDeath /Users/connor/CLionProjects/ProjectOfDeath /Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug /Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug /Users/connor/CLionProjects/ProjectOfDeath/cmake-build-debug/CMakeFiles/ProjectOfDeath.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectOfDeath.dir/depend

