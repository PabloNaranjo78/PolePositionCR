# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GUI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GUI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GUI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GUI.dir/flags.make

CMakeFiles/GUI.dir/main.c.obj: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/main.c.obj: CMakeFiles/GUI.dir/includes_C.rsp
CMakeFiles/GUI.dir/main.c.obj: ../main.c
CMakeFiles/GUI.dir/main.c.obj: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GUI.dir/main.c.obj"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/main.c.obj -MF CMakeFiles\GUI.dir\main.c.obj.d -o CMakeFiles\GUI.dir\main.c.obj -c C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\main.c

CMakeFiles/GUI.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GUI.dir/main.c.i"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\main.c > CMakeFiles\GUI.dir\main.c.i

CMakeFiles/GUI.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GUI.dir/main.c.s"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\main.c -o CMakeFiles\GUI.dir\main.c.s

CMakeFiles/GUI.dir/Window/Game.c.obj: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/Window/Game.c.obj: CMakeFiles/GUI.dir/includes_C.rsp
CMakeFiles/GUI.dir/Window/Game.c.obj: ../Window/Game.c
CMakeFiles/GUI.dir/Window/Game.c.obj: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GUI.dir/Window/Game.c.obj"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/Window/Game.c.obj -MF CMakeFiles\GUI.dir\Window\Game.c.obj.d -o CMakeFiles\GUI.dir\Window\Game.c.obj -c C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\Window\Game.c

CMakeFiles/GUI.dir/Window/Game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GUI.dir/Window/Game.c.i"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\Window\Game.c > CMakeFiles\GUI.dir\Window\Game.c.i

CMakeFiles/GUI.dir/Window/Game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GUI.dir/Window/Game.c.s"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\Window\Game.c -o CMakeFiles\GUI.dir\Window\Game.c.s

CMakeFiles/GUI.dir/cJSON/cJSON.c.obj: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/cJSON/cJSON.c.obj: CMakeFiles/GUI.dir/includes_C.rsp
CMakeFiles/GUI.dir/cJSON/cJSON.c.obj: ../cJSON/cJSON.c
CMakeFiles/GUI.dir/cJSON/cJSON.c.obj: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/GUI.dir/cJSON/cJSON.c.obj"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/cJSON/cJSON.c.obj -MF CMakeFiles\GUI.dir\cJSON\cJSON.c.obj.d -o CMakeFiles\GUI.dir\cJSON\cJSON.c.obj -c C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cJSON\cJSON.c

CMakeFiles/GUI.dir/cJSON/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GUI.dir/cJSON/cJSON.c.i"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cJSON\cJSON.c > CMakeFiles\GUI.dir\cJSON\cJSON.c.i

CMakeFiles/GUI.dir/cJSON/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GUI.dir/cJSON/cJSON.c.s"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cJSON\cJSON.c -o CMakeFiles\GUI.dir\cJSON\cJSON.c.s

CMakeFiles/GUI.dir/Clientes/Cliente.c.obj: CMakeFiles/GUI.dir/flags.make
CMakeFiles/GUI.dir/Clientes/Cliente.c.obj: CMakeFiles/GUI.dir/includes_C.rsp
CMakeFiles/GUI.dir/Clientes/Cliente.c.obj: ../Clientes/Cliente.c
CMakeFiles/GUI.dir/Clientes/Cliente.c.obj: CMakeFiles/GUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/GUI.dir/Clientes/Cliente.c.obj"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GUI.dir/Clientes/Cliente.c.obj -MF CMakeFiles\GUI.dir\Clientes\Cliente.c.obj.d -o CMakeFiles\GUI.dir\Clientes\Cliente.c.obj -c C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\Clientes\Cliente.c

CMakeFiles/GUI.dir/Clientes/Cliente.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GUI.dir/Clientes/Cliente.c.i"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\Clientes\Cliente.c > CMakeFiles\GUI.dir\Clientes\Cliente.c.i

CMakeFiles/GUI.dir/Clientes/Cliente.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GUI.dir/Clientes/Cliente.c.s"
	C:\Users\XPC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.7172.20\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\Clientes\Cliente.c -o CMakeFiles\GUI.dir\Clientes\Cliente.c.s

# Object files for target GUI
GUI_OBJECTS = \
"CMakeFiles/GUI.dir/main.c.obj" \
"CMakeFiles/GUI.dir/Window/Game.c.obj" \
"CMakeFiles/GUI.dir/cJSON/cJSON.c.obj" \
"CMakeFiles/GUI.dir/Clientes/Cliente.c.obj"

# External object files for target GUI
GUI_EXTERNAL_OBJECTS =

GUI.exe: CMakeFiles/GUI.dir/main.c.obj
GUI.exe: CMakeFiles/GUI.dir/Window/Game.c.obj
GUI.exe: CMakeFiles/GUI.dir/cJSON/cJSON.c.obj
GUI.exe: CMakeFiles/GUI.dir/Clientes/Cliente.c.obj
GUI.exe: CMakeFiles/GUI.dir/build.make
GUI.exe: CMakeFiles/GUI.dir/linklibs.rsp
GUI.exe: CMakeFiles/GUI.dir/objects1.rsp
GUI.exe: CMakeFiles/GUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable GUI.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GUI.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GUI.dir/build: GUI.exe
.PHONY : CMakeFiles/GUI.dir/build

CMakeFiles/GUI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GUI.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GUI.dir/clean

CMakeFiles/GUI.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug C:\Users\XPC\Documents\GitHub\PolePositionCR\GUI\cmake-build-debug\CMakeFiles\GUI.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GUI.dir/depend

