# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/workspace_DDSHelloWorld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/workspace_DDSHelloWorld/build

# Include any dependencies generated for this target.
include CMakeFiles/DDSHelloWorldSubscriber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DDSHelloWorldSubscriber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DDSHelloWorldSubscriber.dir/flags.make

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.o: CMakeFiles/DDSHelloWorldSubscriber.dir/flags.make
CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.o: ../src/HelloWorldSubscriber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/workspace_DDSHelloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.o -c /home/parallels/workspace_DDSHelloWorld/src/HelloWorldSubscriber.cpp

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/workspace_DDSHelloWorld/src/HelloWorldSubscriber.cpp > CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.i

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/workspace_DDSHelloWorld/src/HelloWorldSubscriber.cpp -o CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.s

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.o: CMakeFiles/DDSHelloWorldSubscriber.dir/flags.make
CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.o: ../src/HelloWorld.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/workspace_DDSHelloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.o -c /home/parallels/workspace_DDSHelloWorld/src/HelloWorld.cxx

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/workspace_DDSHelloWorld/src/HelloWorld.cxx > CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.i

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/workspace_DDSHelloWorld/src/HelloWorld.cxx -o CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.s

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.o: CMakeFiles/DDSHelloWorldSubscriber.dir/flags.make
CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.o: ../src/HelloWorldPubSubTypes.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/workspace_DDSHelloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.o -c /home/parallels/workspace_DDSHelloWorld/src/HelloWorldPubSubTypes.cxx

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/workspace_DDSHelloWorld/src/HelloWorldPubSubTypes.cxx > CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.i

CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/workspace_DDSHelloWorld/src/HelloWorldPubSubTypes.cxx -o CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.s

# Object files for target DDSHelloWorldSubscriber
DDSHelloWorldSubscriber_OBJECTS = \
"CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.o" \
"CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.o" \
"CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.o"

# External object files for target DDSHelloWorldSubscriber
DDSHelloWorldSubscriber_EXTERNAL_OBJECTS =

DDSHelloWorldSubscriber: CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldSubscriber.cpp.o
DDSHelloWorldSubscriber: CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorld.cxx.o
DDSHelloWorldSubscriber: CMakeFiles/DDSHelloWorldSubscriber.dir/src/HelloWorldPubSubTypes.cxx.o
DDSHelloWorldSubscriber: CMakeFiles/DDSHelloWorldSubscriber.dir/build.make
DDSHelloWorldSubscriber: /home/parallels/Fast-DDS/install/fastrtps/lib/libfastrtps.so.2.10.0
DDSHelloWorldSubscriber: /home/parallels/Fast-DDS/install/fastcdr/lib/libfastcdr.so.1.0.26
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_gapi.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_highgui.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_ml.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_objdetect.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_photo.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_stitching.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_video.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_videoio.so.4.7.0
DDSHelloWorldSubscriber: /home/parallels/Fast-DDS/install/foonathan_memory_vendor/lib/libfoonathan_memory-0.7.3.a
DDSHelloWorldSubscriber: /usr/lib/aarch64-linux-gnu/libtinyxml2.so
DDSHelloWorldSubscriber: /usr/lib/aarch64-linux-gnu/libtinyxml2.so
DDSHelloWorldSubscriber: /usr/lib/aarch64-linux-gnu/libssl.so
DDSHelloWorldSubscriber: /usr/lib/aarch64-linux-gnu/libcrypto.so
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_dnn.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_calib3d.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_features2d.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_flann.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_imgproc.so.4.7.0
DDSHelloWorldSubscriber: /usr/local/lib/libopencv_core.so.4.7.0
DDSHelloWorldSubscriber: CMakeFiles/DDSHelloWorldSubscriber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/workspace_DDSHelloWorld/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DDSHelloWorldSubscriber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DDSHelloWorldSubscriber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DDSHelloWorldSubscriber.dir/build: DDSHelloWorldSubscriber

.PHONY : CMakeFiles/DDSHelloWorldSubscriber.dir/build

CMakeFiles/DDSHelloWorldSubscriber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DDSHelloWorldSubscriber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DDSHelloWorldSubscriber.dir/clean

CMakeFiles/DDSHelloWorldSubscriber.dir/depend:
	cd /home/parallels/workspace_DDSHelloWorld/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/workspace_DDSHelloWorld /home/parallels/workspace_DDSHelloWorld /home/parallels/workspace_DDSHelloWorld/build /home/parallels/workspace_DDSHelloWorld/build /home/parallels/workspace_DDSHelloWorld/build/CMakeFiles/DDSHelloWorldSubscriber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DDSHelloWorldSubscriber.dir/depend

