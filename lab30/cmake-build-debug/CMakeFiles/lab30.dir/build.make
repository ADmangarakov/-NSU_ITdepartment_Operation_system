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
CMAKE_COMMAND = /cygdrive/c/Users/User/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/User/.CLion2019.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lab30.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab30.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab30.dir/flags.make

CMakeFiles/lab30.dir/client.c.o: CMakeFiles/lab30.dir/flags.make
CMakeFiles/lab30.dir/client.c.o: ../client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab30.dir/client.c.o"
	C:/cygwin64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab30.dir/client.c.o   -c "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/client.c"

CMakeFiles/lab30.dir/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab30.dir/client.c.i"
	C:/cygwin64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/client.c" > CMakeFiles/lab30.dir/client.c.i

CMakeFiles/lab30.dir/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab30.dir/client.c.s"
	C:/cygwin64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/client.c" -o CMakeFiles/lab30.dir/client.c.s

CMakeFiles/lab30.dir/server.c.o: CMakeFiles/lab30.dir/flags.make
CMakeFiles/lab30.dir/server.c.o: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab30.dir/server.c.o"
	C:/cygwin64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab30.dir/server.c.o   -c "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/server.c"

CMakeFiles/lab30.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab30.dir/server.c.i"
	C:/cygwin64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/server.c" > CMakeFiles/lab30.dir/server.c.i

CMakeFiles/lab30.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab30.dir/server.c.s"
	C:/cygwin64/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/server.c" -o CMakeFiles/lab30.dir/server.c.s

# Object files for target lab30
lab30_OBJECTS = \
"CMakeFiles/lab30.dir/client.c.o" \
"CMakeFiles/lab30.dir/server.c.o"

# External object files for target lab30
lab30_EXTERNAL_OBJECTS =

lab30.exe: CMakeFiles/lab30.dir/client.c.o
lab30.exe: CMakeFiles/lab30.dir/server.c.o
lab30.exe: CMakeFiles/lab30.dir/build.make
lab30.exe: CMakeFiles/lab30.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lab30.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab30.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab30.dir/build: lab30.exe

.PHONY : CMakeFiles/lab30.dir/build

CMakeFiles/lab30.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab30.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab30.dir/clean

CMakeFiles/lab30.dir/depend:
	cd "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30" "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30" "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug" "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug" "/cygdrive/c/Users/User/Documents/NSU/Studing/Operation System/MyLabs/-NSU_ITdepartment_Operation_system/lab30/cmake-build-debug/CMakeFiles/lab30.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab30.dir/depend

