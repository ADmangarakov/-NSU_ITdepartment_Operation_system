# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/NSU/OS/env_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/NSU/OS/env_test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/env_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/env_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/env_test.dir/flags.make

CMakeFiles/env_test.dir/main.c.o: CMakeFiles/env_test.dir/flags.make
CMakeFiles/env_test.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/NSU/OS/env_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/env_test.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/env_test.dir/main.c.o   -c /home/alex/NSU/OS/env_test/main.c

CMakeFiles/env_test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/env_test.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alex/NSU/OS/env_test/main.c > CMakeFiles/env_test.dir/main.c.i

CMakeFiles/env_test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/env_test.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alex/NSU/OS/env_test/main.c -o CMakeFiles/env_test.dir/main.c.s

# Object files for target env_test
env_test_OBJECTS = \
"CMakeFiles/env_test.dir/main.c.o"

# External object files for target env_test
env_test_EXTERNAL_OBJECTS =

env_test: CMakeFiles/env_test.dir/main.c.o
env_test: CMakeFiles/env_test.dir/build.make
env_test: CMakeFiles/env_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/NSU/OS/env_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable env_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/env_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/env_test.dir/build: env_test

.PHONY : CMakeFiles/env_test.dir/build

CMakeFiles/env_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/env_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/env_test.dir/clean

CMakeFiles/env_test.dir/depend:
	cd /home/alex/NSU/OS/env_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/NSU/OS/env_test /home/alex/NSU/OS/env_test /home/alex/NSU/OS/env_test/cmake-build-debug /home/alex/NSU/OS/env_test/cmake-build-debug /home/alex/NSU/OS/env_test/cmake-build-debug/CMakeFiles/env_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/env_test.dir/depend

