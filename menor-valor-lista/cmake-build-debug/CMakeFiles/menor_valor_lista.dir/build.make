# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/jeferson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jeferson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeferson/CLionProjects/Estrutura/menor-valor-lista

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/menor_valor_lista.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/menor_valor_lista.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/menor_valor_lista.dir/flags.make

CMakeFiles/menor_valor_lista.dir/main.c.o: CMakeFiles/menor_valor_lista.dir/flags.make
CMakeFiles/menor_valor_lista.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeferson/CLionProjects/Estrutura/menor-valor-lista/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/menor_valor_lista.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/menor_valor_lista.dir/main.c.o   -c /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/main.c

CMakeFiles/menor_valor_lista.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/menor_valor_lista.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/main.c > CMakeFiles/menor_valor_lista.dir/main.c.i

CMakeFiles/menor_valor_lista.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/menor_valor_lista.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/main.c -o CMakeFiles/menor_valor_lista.dir/main.c.s

CMakeFiles/menor_valor_lista.dir/main.c.o.requires:

.PHONY : CMakeFiles/menor_valor_lista.dir/main.c.o.requires

CMakeFiles/menor_valor_lista.dir/main.c.o.provides: CMakeFiles/menor_valor_lista.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/menor_valor_lista.dir/build.make CMakeFiles/menor_valor_lista.dir/main.c.o.provides.build
.PHONY : CMakeFiles/menor_valor_lista.dir/main.c.o.provides

CMakeFiles/menor_valor_lista.dir/main.c.o.provides.build: CMakeFiles/menor_valor_lista.dir/main.c.o


# Object files for target menor_valor_lista
menor_valor_lista_OBJECTS = \
"CMakeFiles/menor_valor_lista.dir/main.c.o"

# External object files for target menor_valor_lista
menor_valor_lista_EXTERNAL_OBJECTS =

menor_valor_lista: CMakeFiles/menor_valor_lista.dir/main.c.o
menor_valor_lista: CMakeFiles/menor_valor_lista.dir/build.make
menor_valor_lista: CMakeFiles/menor_valor_lista.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeferson/CLionProjects/Estrutura/menor-valor-lista/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable menor_valor_lista"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/menor_valor_lista.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/menor_valor_lista.dir/build: menor_valor_lista

.PHONY : CMakeFiles/menor_valor_lista.dir/build

CMakeFiles/menor_valor_lista.dir/requires: CMakeFiles/menor_valor_lista.dir/main.c.o.requires

.PHONY : CMakeFiles/menor_valor_lista.dir/requires

CMakeFiles/menor_valor_lista.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/menor_valor_lista.dir/cmake_clean.cmake
.PHONY : CMakeFiles/menor_valor_lista.dir/clean

CMakeFiles/menor_valor_lista.dir/depend:
	cd /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeferson/CLionProjects/Estrutura/menor-valor-lista /home/jeferson/CLionProjects/Estrutura/menor-valor-lista /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/cmake-build-debug /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/cmake-build-debug /home/jeferson/CLionProjects/Estrutura/menor-valor-lista/cmake-build-debug/CMakeFiles/menor_valor_lista.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/menor_valor_lista.dir/depend

