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
CMAKE_COMMAND = /home/kimminho/바탕화면/clion-2018.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/kimminho/바탕화면/clion-2018.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/semprodcons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/semprodcons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/semprodcons.dir/flags.make

CMakeFiles/semprodcons.dir/main.cpp.o: CMakeFiles/semprodcons.dir/flags.make
CMakeFiles/semprodcons.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/semprodcons.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/semprodcons.dir/main.cpp.o -c /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/main.cpp

CMakeFiles/semprodcons.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/semprodcons.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/main.cpp > CMakeFiles/semprodcons.dir/main.cpp.i

CMakeFiles/semprodcons.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/semprodcons.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/main.cpp -o CMakeFiles/semprodcons.dir/main.cpp.s

CMakeFiles/semprodcons.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/semprodcons.dir/main.cpp.o.requires

CMakeFiles/semprodcons.dir/main.cpp.o.provides: CMakeFiles/semprodcons.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/semprodcons.dir/build.make CMakeFiles/semprodcons.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/semprodcons.dir/main.cpp.o.provides

CMakeFiles/semprodcons.dir/main.cpp.o.provides.build: CMakeFiles/semprodcons.dir/main.cpp.o


# Object files for target semprodcons
semprodcons_OBJECTS = \
"CMakeFiles/semprodcons.dir/main.cpp.o"

# External object files for target semprodcons
semprodcons_EXTERNAL_OBJECTS =

semprodcons: CMakeFiles/semprodcons.dir/main.cpp.o
semprodcons: CMakeFiles/semprodcons.dir/build.make
semprodcons: CMakeFiles/semprodcons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable semprodcons"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/semprodcons.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/semprodcons.dir/build: semprodcons

.PHONY : CMakeFiles/semprodcons.dir/build

CMakeFiles/semprodcons.dir/requires: CMakeFiles/semprodcons.dir/main.cpp.o.requires

.PHONY : CMakeFiles/semprodcons.dir/requires

CMakeFiles/semprodcons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/semprodcons.dir/cmake_clean.cmake
.PHONY : CMakeFiles/semprodcons.dir/clean

CMakeFiles/semprodcons.dir/depend:
	cd /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/cmake-build-debug /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/cmake-build-debug /home/kimminho/바탕화면/my_project/cppProject/LinuxAssignment/assignment7_synchronization/semprodcons/cmake-build-debug/CMakeFiles/semprodcons.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/semprodcons.dir/depend

