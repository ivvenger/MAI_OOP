# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/boopie/Desktop/OOP/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/boopie/Desktop/OOP/lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/lab3_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab3_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3_lib.dir/flags.make

CMakeFiles/lab3_lib.dir/src/Array.cpp.o: CMakeFiles/lab3_lib.dir/flags.make
CMakeFiles/lab3_lib.dir/src/Array.cpp.o: /Users/boopie/Desktop/OOP/lab3/src/Array.cpp
CMakeFiles/lab3_lib.dir/src/Array.cpp.o: CMakeFiles/lab3_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/boopie/Desktop/OOP/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab3_lib.dir/src/Array.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3_lib.dir/src/Array.cpp.o -MF CMakeFiles/lab3_lib.dir/src/Array.cpp.o.d -o CMakeFiles/lab3_lib.dir/src/Array.cpp.o -c /Users/boopie/Desktop/OOP/lab3/src/Array.cpp

CMakeFiles/lab3_lib.dir/src/Array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3_lib.dir/src/Array.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/boopie/Desktop/OOP/lab3/src/Array.cpp > CMakeFiles/lab3_lib.dir/src/Array.cpp.i

CMakeFiles/lab3_lib.dir/src/Array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3_lib.dir/src/Array.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/boopie/Desktop/OOP/lab3/src/Array.cpp -o CMakeFiles/lab3_lib.dir/src/Array.cpp.s

CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o: CMakeFiles/lab3_lib.dir/flags.make
CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o: /Users/boopie/Desktop/OOP/lab3/src/Rectangle.cpp
CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o: CMakeFiles/lab3_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/boopie/Desktop/OOP/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o -MF CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o.d -o CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o -c /Users/boopie/Desktop/OOP/lab3/src/Rectangle.cpp

CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/boopie/Desktop/OOP/lab3/src/Rectangle.cpp > CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.i

CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/boopie/Desktop/OOP/lab3/src/Rectangle.cpp -o CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.s

CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o: CMakeFiles/lab3_lib.dir/flags.make
CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o: /Users/boopie/Desktop/OOP/lab3/src/Rhombus.cpp
CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o: CMakeFiles/lab3_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/boopie/Desktop/OOP/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o -MF CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o.d -o CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o -c /Users/boopie/Desktop/OOP/lab3/src/Rhombus.cpp

CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/boopie/Desktop/OOP/lab3/src/Rhombus.cpp > CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.i

CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/boopie/Desktop/OOP/lab3/src/Rhombus.cpp -o CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.s

CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o: CMakeFiles/lab3_lib.dir/flags.make
CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o: /Users/boopie/Desktop/OOP/lab3/src/Trapezoid.cpp
CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o: CMakeFiles/lab3_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/boopie/Desktop/OOP/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o -MF CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o.d -o CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o -c /Users/boopie/Desktop/OOP/lab3/src/Trapezoid.cpp

CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/boopie/Desktop/OOP/lab3/src/Trapezoid.cpp > CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.i

CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/boopie/Desktop/OOP/lab3/src/Trapezoid.cpp -o CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.s

# Object files for target lab3_lib
lab3_lib_OBJECTS = \
"CMakeFiles/lab3_lib.dir/src/Array.cpp.o" \
"CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o" \
"CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o" \
"CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o"

# External object files for target lab3_lib
lab3_lib_EXTERNAL_OBJECTS =

liblab3_lib.a: CMakeFiles/lab3_lib.dir/src/Array.cpp.o
liblab3_lib.a: CMakeFiles/lab3_lib.dir/src/Rectangle.cpp.o
liblab3_lib.a: CMakeFiles/lab3_lib.dir/src/Rhombus.cpp.o
liblab3_lib.a: CMakeFiles/lab3_lib.dir/src/Trapezoid.cpp.o
liblab3_lib.a: CMakeFiles/lab3_lib.dir/build.make
liblab3_lib.a: CMakeFiles/lab3_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/boopie/Desktop/OOP/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library liblab3_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lab3_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3_lib.dir/build: liblab3_lib.a
.PHONY : CMakeFiles/lab3_lib.dir/build

CMakeFiles/lab3_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab3_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab3_lib.dir/clean

CMakeFiles/lab3_lib.dir/depend:
	cd /Users/boopie/Desktop/OOP/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/boopie/Desktop/OOP/lab3 /Users/boopie/Desktop/OOP/lab3 /Users/boopie/Desktop/OOP/lab3/build /Users/boopie/Desktop/OOP/lab3/build /Users/boopie/Desktop/OOP/lab3/build/CMakeFiles/lab3_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lab3_lib.dir/depend
