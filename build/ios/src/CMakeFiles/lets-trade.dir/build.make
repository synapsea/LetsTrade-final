# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\exit2\Documents\Projects\Lets-Trade

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios

# Include any dependencies generated for this target.
include src/CMakeFiles/lets-trade.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lets-trade.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lets-trade.dir/flags.make

src/CMakeFiles/lets-trade.dir/main.cpp.obj: src/CMakeFiles/lets-trade.dir/flags.make
src/CMakeFiles/lets-trade.dir/main.cpp.obj: src/CMakeFiles/lets-trade.dir/includes_CXX.rsp
src/CMakeFiles/lets-trade.dir/main.cpp.obj: ../../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lets-trade.dir/main.cpp.obj"
	cd /d C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src && C:\ProgramData\chocolatey\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lets-trade.dir\main.cpp.obj -c C:\Users\exit2\Documents\Projects\Lets-Trade\src\main.cpp

src/CMakeFiles/lets-trade.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lets-trade.dir/main.cpp.i"
	cd /d C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src && C:\ProgramData\chocolatey\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\exit2\Documents\Projects\Lets-Trade\src\main.cpp > CMakeFiles\lets-trade.dir\main.cpp.i

src/CMakeFiles/lets-trade.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lets-trade.dir/main.cpp.s"
	cd /d C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src && C:\ProgramData\chocolatey\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\exit2\Documents\Projects\Lets-Trade\src\main.cpp -o CMakeFiles\lets-trade.dir\main.cpp.s

# Object files for target lets-trade
lets__trade_OBJECTS = \
"CMakeFiles/lets-trade.dir/main.cpp.obj"

# External object files for target lets-trade
lets__trade_EXTERNAL_OBJECTS =

src/lets-trade.exe: src/CMakeFiles/lets-trade.dir/main.cpp.obj
src/lets-trade.exe: src/CMakeFiles/lets-trade.dir/build.make
src/lets-trade.exe: src/CMakeFiles/lets-trade.dir/linklibs.rsp
src/lets-trade.exe: src/CMakeFiles/lets-trade.dir/objects1.rsp
src/lets-trade.exe: src/CMakeFiles/lets-trade.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lets-trade.exe"
	cd /d C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lets-trade.dir\link.txt --verbose=$(VERBOSE)
	cd /d C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src && "C:\Program Files\CMake\bin\cmake.exe" -E copy C:/Users/exit2/Documents/Projects/Lets-Trade/src/companies.csv C:/Users/exit2/Documents/Projects/Lets-Trade/build/ios/src/Debug/companies.csv
	cd /d C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src && "C:\Program Files\CMake\bin\cmake.exe" -E copy C:/Users/exit2/Documents/Projects/Lets-Trade/src/companies.csv C:/Users/exit2/Documents/Projects/Lets-Trade/build/ios/src/companies.csv

# Rule to build all files generated by this target.
src/CMakeFiles/lets-trade.dir/build: src/lets-trade.exe

.PHONY : src/CMakeFiles/lets-trade.dir/build

src/CMakeFiles/lets-trade.dir/clean:
	cd /d C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src && $(CMAKE_COMMAND) -P CMakeFiles\lets-trade.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/lets-trade.dir/clean

src/CMakeFiles/lets-trade.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\exit2\Documents\Projects\Lets-Trade C:\Users\exit2\Documents\Projects\Lets-Trade\src C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src C:\Users\exit2\Documents\Projects\Lets-Trade\build\ios\src\CMakeFiles\lets-trade.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lets-trade.dir/depend

