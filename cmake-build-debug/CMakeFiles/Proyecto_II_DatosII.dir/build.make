# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /home/luis/Descargas/CLion-2022.2.3/clion-2022.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/luis/Descargas/CLion-2022.2.3/clion-2022.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luis/CLionProjects/Proyecto_II_DatosII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/CLionProjects/Proyecto_II_DatosII/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Proyecto_II_DatosII.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Proyecto_II_DatosII.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Proyecto_II_DatosII.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proyecto_II_DatosII.dir/flags.make

CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o: CMakeFiles/Proyecto_II_DatosII.dir/flags.make
CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o: CMakeFiles/Proyecto_II_DatosII.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/CLionProjects/Proyecto_II_DatosII/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o -MF CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o.d -o CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o -c /home/luis/CLionProjects/Proyecto_II_DatosII/src/main.cpp

CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/CLionProjects/Proyecto_II_DatosII/src/main.cpp > CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.i

CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/CLionProjects/Proyecto_II_DatosII/src/main.cpp -o CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.s

# Object files for target Proyecto_II_DatosII
Proyecto_II_DatosII_OBJECTS = \
"CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o"

# External object files for target Proyecto_II_DatosII
Proyecto_II_DatosII_EXTERNAL_OBJECTS =

Proyecto_II_DatosII: CMakeFiles/Proyecto_II_DatosII.dir/src/main.cpp.o
Proyecto_II_DatosII: CMakeFiles/Proyecto_II_DatosII.dir/build.make
Proyecto_II_DatosII: CMakeFiles/Proyecto_II_DatosII.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/CLionProjects/Proyecto_II_DatosII/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Proyecto_II_DatosII"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Proyecto_II_DatosII.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proyecto_II_DatosII.dir/build: Proyecto_II_DatosII
.PHONY : CMakeFiles/Proyecto_II_DatosII.dir/build

CMakeFiles/Proyecto_II_DatosII.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Proyecto_II_DatosII.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Proyecto_II_DatosII.dir/clean

CMakeFiles/Proyecto_II_DatosII.dir/depend:
	cd /home/luis/CLionProjects/Proyecto_II_DatosII/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/CLionProjects/Proyecto_II_DatosII /home/luis/CLionProjects/Proyecto_II_DatosII /home/luis/CLionProjects/Proyecto_II_DatosII/cmake-build-debug /home/luis/CLionProjects/Proyecto_II_DatosII/cmake-build-debug /home/luis/CLionProjects/Proyecto_II_DatosII/cmake-build-debug/CMakeFiles/Proyecto_II_DatosII.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Proyecto_II_DatosII.dir/depend
