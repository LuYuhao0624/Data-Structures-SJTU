# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/k_tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/k_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/k_tree.dir/flags.make

CMakeFiles/k_tree.dir/main.cpp.obj: CMakeFiles/k_tree.dir/flags.make
CMakeFiles/k_tree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/k_tree.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\k_tree.dir\main.cpp.obj -c "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\main.cpp"

CMakeFiles/k_tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k_tree.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\main.cpp" > CMakeFiles\k_tree.dir\main.cpp.i

CMakeFiles/k_tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k_tree.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\main.cpp" -o CMakeFiles\k_tree.dir\main.cpp.s

# Object files for target k_tree
k_tree_OBJECTS = \
"CMakeFiles/k_tree.dir/main.cpp.obj"

# External object files for target k_tree
k_tree_EXTERNAL_OBJECTS =

k_tree.exe: CMakeFiles/k_tree.dir/main.cpp.obj
k_tree.exe: CMakeFiles/k_tree.dir/build.make
k_tree.exe: CMakeFiles/k_tree.dir/linklibs.rsp
k_tree.exe: CMakeFiles/k_tree.dir/objects1.rsp
k_tree.exe: CMakeFiles/k_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable k_tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\k_tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/k_tree.dir/build: k_tree.exe

.PHONY : CMakeFiles/k_tree.dir/build

CMakeFiles/k_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\k_tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/k_tree.dir/clean

CMakeFiles/k_tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)" "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)" "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\cmake-build-debug" "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\cmake-build-debug" "C:\Users\10752\Desktop\Docs\Works\C++\data structures exercises\k_tree(4011)\cmake-build-debug\CMakeFiles\k_tree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/k_tree.dir/depend

