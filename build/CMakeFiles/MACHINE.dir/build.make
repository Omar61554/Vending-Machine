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
CMAKE_SOURCE_DIR = /home/amin/Desktop/VendingMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amin/Desktop/VendingMachine/build

# Include any dependencies generated for this target.
include CMakeFiles/MACHINE.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MACHINE.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MACHINE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MACHINE.dir/flags.make

CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o: CMakeFiles/MACHINE.dir/flags.make
CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o: ../Machine/Machine.cpp
CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o: CMakeFiles/MACHINE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amin/Desktop/VendingMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o -MF CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o.d -o CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o -c /home/amin/Desktop/VendingMachine/Machine/Machine.cpp

CMakeFiles/MACHINE.dir/Machine/Machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MACHINE.dir/Machine/Machine.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amin/Desktop/VendingMachine/Machine/Machine.cpp > CMakeFiles/MACHINE.dir/Machine/Machine.cpp.i

CMakeFiles/MACHINE.dir/Machine/Machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MACHINE.dir/Machine/Machine.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amin/Desktop/VendingMachine/Machine/Machine.cpp -o CMakeFiles/MACHINE.dir/Machine/Machine.cpp.s

# Object files for target MACHINE
MACHINE_OBJECTS = \
"CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o"

# External object files for target MACHINE
MACHINE_EXTERNAL_OBJECTS =

libMACHINE.a: CMakeFiles/MACHINE.dir/Machine/Machine.cpp.o
libMACHINE.a: CMakeFiles/MACHINE.dir/build.make
libMACHINE.a: CMakeFiles/MACHINE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amin/Desktop/VendingMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMACHINE.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MACHINE.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MACHINE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MACHINE.dir/build: libMACHINE.a
.PHONY : CMakeFiles/MACHINE.dir/build

CMakeFiles/MACHINE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MACHINE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MACHINE.dir/clean

CMakeFiles/MACHINE.dir/depend:
	cd /home/amin/Desktop/VendingMachine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amin/Desktop/VendingMachine /home/amin/Desktop/VendingMachine /home/amin/Desktop/VendingMachine/build /home/amin/Desktop/VendingMachine/build /home/amin/Desktop/VendingMachine/build/CMakeFiles/MACHINE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MACHINE.dir/depend
