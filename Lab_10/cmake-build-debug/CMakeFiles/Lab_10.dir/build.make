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
CMAKE_SOURCE_DIR = /Users/connor/CLionProjects/Lab_10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/connor/CLionProjects/Lab_10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab_10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_10.dir/flags.make

CMakeFiles/Lab_10.dir/main.cpp.o: CMakeFiles/Lab_10.dir/flags.make
CMakeFiles/Lab_10.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connor/CLionProjects/Lab_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_10.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_10.dir/main.cpp.o -c /Users/connor/CLionProjects/Lab_10/main.cpp

CMakeFiles/Lab_10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_10.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connor/CLionProjects/Lab_10/main.cpp > CMakeFiles/Lab_10.dir/main.cpp.i

CMakeFiles/Lab_10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_10.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connor/CLionProjects/Lab_10/main.cpp -o CMakeFiles/Lab_10.dir/main.cpp.s

CMakeFiles/Lab_10.dir/WordInfo.cpp.o: CMakeFiles/Lab_10.dir/flags.make
CMakeFiles/Lab_10.dir/WordInfo.cpp.o: ../WordInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connor/CLionProjects/Lab_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab_10.dir/WordInfo.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab_10.dir/WordInfo.cpp.o -c /Users/connor/CLionProjects/Lab_10/WordInfo.cpp

CMakeFiles/Lab_10.dir/WordInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_10.dir/WordInfo.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connor/CLionProjects/Lab_10/WordInfo.cpp > CMakeFiles/Lab_10.dir/WordInfo.cpp.i

CMakeFiles/Lab_10.dir/WordInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_10.dir/WordInfo.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connor/CLionProjects/Lab_10/WordInfo.cpp -o CMakeFiles/Lab_10.dir/WordInfo.cpp.s

# Object files for target Lab_10
Lab_10_OBJECTS = \
"CMakeFiles/Lab_10.dir/main.cpp.o" \
"CMakeFiles/Lab_10.dir/WordInfo.cpp.o"

# External object files for target Lab_10
Lab_10_EXTERNAL_OBJECTS =

Lab_10: CMakeFiles/Lab_10.dir/main.cpp.o
Lab_10: CMakeFiles/Lab_10.dir/WordInfo.cpp.o
Lab_10: CMakeFiles/Lab_10.dir/build.make
Lab_10: CMakeFiles/Lab_10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/connor/CLionProjects/Lab_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab_10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab_10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_10.dir/build: Lab_10

.PHONY : CMakeFiles/Lab_10.dir/build

CMakeFiles/Lab_10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab_10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab_10.dir/clean

CMakeFiles/Lab_10.dir/depend:
	cd /Users/connor/CLionProjects/Lab_10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/connor/CLionProjects/Lab_10 /Users/connor/CLionProjects/Lab_10 /Users/connor/CLionProjects/Lab_10/cmake-build-debug /Users/connor/CLionProjects/Lab_10/cmake-build-debug /Users/connor/CLionProjects/Lab_10/cmake-build-debug/CMakeFiles/Lab_10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab_10.dir/depend

