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
CMAKE_COMMAND = /opt/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haziel/CLionProjects/Grafo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haziel/CLionProjects/Grafo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Server.dir/flags.make

CMakeFiles/Server.dir/SocketServer/Server.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/SocketServer/Server.cpp.o: ../SocketServer/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haziel/CLionProjects/Grafo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server.dir/SocketServer/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/SocketServer/Server.cpp.o -c /home/haziel/CLionProjects/Grafo/SocketServer/Server.cpp

CMakeFiles/Server.dir/SocketServer/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/SocketServer/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haziel/CLionProjects/Grafo/SocketServer/Server.cpp > CMakeFiles/Server.dir/SocketServer/Server.cpp.i

CMakeFiles/Server.dir/SocketServer/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/SocketServer/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haziel/CLionProjects/Grafo/SocketServer/Server.cpp -o CMakeFiles/Server.dir/SocketServer/Server.cpp.s

CMakeFiles/Server.dir/grafo/Vertice.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/grafo/Vertice.cpp.o: ../grafo/Vertice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haziel/CLionProjects/Grafo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server.dir/grafo/Vertice.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/grafo/Vertice.cpp.o -c /home/haziel/CLionProjects/Grafo/grafo/Vertice.cpp

CMakeFiles/Server.dir/grafo/Vertice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/grafo/Vertice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haziel/CLionProjects/Grafo/grafo/Vertice.cpp > CMakeFiles/Server.dir/grafo/Vertice.cpp.i

CMakeFiles/Server.dir/grafo/Vertice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/grafo/Vertice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haziel/CLionProjects/Grafo/grafo/Vertice.cpp -o CMakeFiles/Server.dir/grafo/Vertice.cpp.s

CMakeFiles/Server.dir/grafo/Arista.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/grafo/Arista.cpp.o: ../grafo/Arista.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haziel/CLionProjects/Grafo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Server.dir/grafo/Arista.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/grafo/Arista.cpp.o -c /home/haziel/CLionProjects/Grafo/grafo/Arista.cpp

CMakeFiles/Server.dir/grafo/Arista.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/grafo/Arista.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haziel/CLionProjects/Grafo/grafo/Arista.cpp > CMakeFiles/Server.dir/grafo/Arista.cpp.i

CMakeFiles/Server.dir/grafo/Arista.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/grafo/Arista.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haziel/CLionProjects/Grafo/grafo/Arista.cpp -o CMakeFiles/Server.dir/grafo/Arista.cpp.s

CMakeFiles/Server.dir/grafo/Grafo.cpp.o: CMakeFiles/Server.dir/flags.make
CMakeFiles/Server.dir/grafo/Grafo.cpp.o: ../grafo/Grafo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/haziel/CLionProjects/Grafo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Server.dir/grafo/Grafo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Server.dir/grafo/Grafo.cpp.o -c /home/haziel/CLionProjects/Grafo/grafo/Grafo.cpp

CMakeFiles/Server.dir/grafo/Grafo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server.dir/grafo/Grafo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/haziel/CLionProjects/Grafo/grafo/Grafo.cpp > CMakeFiles/Server.dir/grafo/Grafo.cpp.i

CMakeFiles/Server.dir/grafo/Grafo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server.dir/grafo/Grafo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/haziel/CLionProjects/Grafo/grafo/Grafo.cpp -o CMakeFiles/Server.dir/grafo/Grafo.cpp.s

# Object files for target Server
Server_OBJECTS = \
"CMakeFiles/Server.dir/SocketServer/Server.cpp.o" \
"CMakeFiles/Server.dir/grafo/Vertice.cpp.o" \
"CMakeFiles/Server.dir/grafo/Arista.cpp.o" \
"CMakeFiles/Server.dir/grafo/Grafo.cpp.o"

# External object files for target Server
Server_EXTERNAL_OBJECTS =

Server: CMakeFiles/Server.dir/SocketServer/Server.cpp.o
Server: CMakeFiles/Server.dir/grafo/Vertice.cpp.o
Server: CMakeFiles/Server.dir/grafo/Arista.cpp.o
Server: CMakeFiles/Server.dir/grafo/Grafo.cpp.o
Server: CMakeFiles/Server.dir/build.make
Server: CMakeFiles/Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/haziel/CLionProjects/Grafo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Server.dir/build: Server

.PHONY : CMakeFiles/Server.dir/build

CMakeFiles/Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Server.dir/clean

CMakeFiles/Server.dir/depend:
	cd /home/haziel/CLionProjects/Grafo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/haziel/CLionProjects/Grafo /home/haziel/CLionProjects/Grafo /home/haziel/CLionProjects/Grafo/cmake-build-debug /home/haziel/CLionProjects/Grafo/cmake-build-debug /home/haziel/CLionProjects/Grafo/cmake-build-debug/CMakeFiles/Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Server.dir/depend
