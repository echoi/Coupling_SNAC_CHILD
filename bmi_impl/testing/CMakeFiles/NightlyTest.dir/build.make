# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl

# Utility rule file for NightlyTest.

# Include the progress variables for this target.
include testing/CMakeFiles/NightlyTest.dir/progress.make

testing/CMakeFiles/NightlyTest:
	cd /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl/testing && /opt/local/bin/ctest -D NightlyTest

NightlyTest: testing/CMakeFiles/NightlyTest
NightlyTest: testing/CMakeFiles/NightlyTest.dir/build.make
.PHONY : NightlyTest

# Rule to build all files generated by this target.
testing/CMakeFiles/NightlyTest.dir/build: NightlyTest
.PHONY : testing/CMakeFiles/NightlyTest.dir/build

testing/CMakeFiles/NightlyTest.dir/clean:
	cd /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl/testing && $(CMAKE_COMMAND) -P CMakeFiles/NightlyTest.dir/cmake_clean.cmake
.PHONY : testing/CMakeFiles/NightlyTest.dir/clean

testing/CMakeFiles/NightlyTest.dir/depend:
	cd /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl/testing /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl/testing /Users/eunseo/projects/Coupling_SNAC_CHILD/bmi_impl/testing/CMakeFiles/NightlyTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : testing/CMakeFiles/NightlyTest.dir/depend

