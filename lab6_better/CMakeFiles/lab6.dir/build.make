# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/giang/projects/cg/lab6_better

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/giang/projects/cg/lab6_better

# Include any dependencies generated for this target.
include CMakeFiles/lab6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6.dir/flags.make

CMakeFiles/lab6.dir/main.cpp.o: CMakeFiles/lab6.dir/flags.make
CMakeFiles/lab6.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/giang/projects/cg/lab6_better/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab6.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab6.dir/main.cpp.o -c /home/giang/projects/cg/lab6_better/main.cpp

CMakeFiles/lab6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/giang/projects/cg/lab6_better/main.cpp > CMakeFiles/lab6.dir/main.cpp.i

CMakeFiles/lab6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/giang/projects/cg/lab6_better/main.cpp -o CMakeFiles/lab6.dir/main.cpp.s

CMakeFiles/lab6.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/lab6.dir/main.cpp.o.requires

CMakeFiles/lab6.dir/main.cpp.o.provides: CMakeFiles/lab6.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab6.dir/build.make CMakeFiles/lab6.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lab6.dir/main.cpp.o.provides

CMakeFiles/lab6.dir/main.cpp.o.provides.build: CMakeFiles/lab6.dir/main.cpp.o

CMakeFiles/lab6.dir/Stick.cpp.o: CMakeFiles/lab6.dir/flags.make
CMakeFiles/lab6.dir/Stick.cpp.o: Stick.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/giang/projects/cg/lab6_better/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab6.dir/Stick.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab6.dir/Stick.cpp.o -c /home/giang/projects/cg/lab6_better/Stick.cpp

CMakeFiles/lab6.dir/Stick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6.dir/Stick.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/giang/projects/cg/lab6_better/Stick.cpp > CMakeFiles/lab6.dir/Stick.cpp.i

CMakeFiles/lab6.dir/Stick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6.dir/Stick.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/giang/projects/cg/lab6_better/Stick.cpp -o CMakeFiles/lab6.dir/Stick.cpp.s

CMakeFiles/lab6.dir/Stick.cpp.o.requires:
.PHONY : CMakeFiles/lab6.dir/Stick.cpp.o.requires

CMakeFiles/lab6.dir/Stick.cpp.o.provides: CMakeFiles/lab6.dir/Stick.cpp.o.requires
	$(MAKE) -f CMakeFiles/lab6.dir/build.make CMakeFiles/lab6.dir/Stick.cpp.o.provides.build
.PHONY : CMakeFiles/lab6.dir/Stick.cpp.o.provides

CMakeFiles/lab6.dir/Stick.cpp.o.provides.build: CMakeFiles/lab6.dir/Stick.cpp.o

# Object files for target lab6
lab6_OBJECTS = \
"CMakeFiles/lab6.dir/main.cpp.o" \
"CMakeFiles/lab6.dir/Stick.cpp.o"

# External object files for target lab6
lab6_EXTERNAL_OBJECTS =

lab6: CMakeFiles/lab6.dir/main.cpp.o
lab6: CMakeFiles/lab6.dir/Stick.cpp.o
lab6: CMakeFiles/lab6.dir/build.make
lab6: /usr/lib/x86_64-linux-gnu/libGLU.so
lab6: /usr/lib/x86_64-linux-gnu/libGL.so
lab6: /usr/lib/x86_64-linux-gnu/libglut.so
lab6: /usr/lib/x86_64-linux-gnu/libXmu.so
lab6: /usr/lib/x86_64-linux-gnu/libXi.so
lab6: CMakeFiles/lab6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lab6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6.dir/build: lab6
.PHONY : CMakeFiles/lab6.dir/build

CMakeFiles/lab6.dir/requires: CMakeFiles/lab6.dir/main.cpp.o.requires
CMakeFiles/lab6.dir/requires: CMakeFiles/lab6.dir/Stick.cpp.o.requires
.PHONY : CMakeFiles/lab6.dir/requires

CMakeFiles/lab6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab6.dir/clean

CMakeFiles/lab6.dir/depend:
	cd /home/giang/projects/cg/lab6_better && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/giang/projects/cg/lab6_better /home/giang/projects/cg/lab6_better /home/giang/projects/cg/lab6_better /home/giang/projects/cg/lab6_better /home/giang/projects/cg/lab6_better/CMakeFiles/lab6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab6.dir/depend

