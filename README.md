Lab 3 - Installing prerequisite software
========================================

Lab machines
------------

The compiler and CMake should already be installed. Skip to "Install glm,
GLFW, and GLEW" below.


Ubuntu Linux
------------

You'll need the following if you don't have them already.

	> sudo apt-get update
	> sudo apt-get install g++
	> sudo apt-get install cmake
	> sudo apt-get install freeglut3-dev
	> sudo apt-get install libxrandr-dev
	> sudo apt-get install libxinerama-dev
	> sudo apt-get install libxcursor-dev
	> sudo apt-get install libglfw3-dev
	> sudo apt-get install libglfw3-dev


Mac OS X
--------

You can use homebrew/macports or install these manually.

- Xcode developer tools. You'll need to log in with your Apple ID.
- CMake (<http://cmake.org/download/>)
- [GLM](http://brewformulas.org/Glm)
- [GLFW3](http://brewformulas.org/glfw)

Make sure the commands `g++` and `cmake` work from the command prompt.


Windows
-------

You'll need to download these manually.

- Visual Studio (Visual C++). Any version should work. I've tested Visual
  Studio 2015 (aka version 14) on Windows 8.
- CMake (<http://cmake.org/download/>). Make sure to add CMake to the system
  path when asked to do so.

Make sure the command `cmake` works from the command prompt.

Additionally, download the latest [GLM](https://github.com/g-truc/glm/tags)
and [64bit binaries for GLFW](https://github.com/glfw/glfw/releases/tag/3.2.1).

Place these in your `Visual Studio 2017`/`SDKs` folder. You will need to create
`SDKs`.


Building and Running the Lab/Assignment
=======================================


All platforms
-------------

Download and extract the lab file:

We'll perform an "out-of- source" build, which means that the binary files
will not be in the same directory as the source files. In the folder that
contains CMakeLists.txt, run the following.

	> mkdir build
	> cd build

Then run one of the following *from the build folder*, depending on your
choice of platform and IDE.


OSX & Linux Makefile
--------------------

	> cmake ..

This will generate a Makefile that you can use to compile your code. To
compile the code, run the generated Makefile.

	> make -j4

The `-j` argument speeds up the compilation by multithreading the compiler.
This will generate an executable, which you can run by typing

	> ./Lab3 ../resources

To build in release mode, use `ccmake ..` and change `CMAKE_BUILD_TYPE` to
`Release`. Press 'c' to configure then 'g' to generate. Now `make -j4` will
build in release mode.

To change the compiler, read [this
page](http://cmake.org/Wiki/CMake_FAQ#How_do_I_use_a_different_compiler.3F).
The best way is to use environment variables before calling cmake. For
example, to use the Intel C++ compiler:

	> which icpc # copy the path
	> CXX=/path/to/icpc cmake ..


OSX Xcode
---------

	> cmake -G Xcode ..

This will generate `Lab3.xcodeproj` project that you can open with Xcode.

- To run, change the target to `Lab00` by going to Product -> Scheme -> Lab00.
  Then click on the play button or press Command+R to run the application.
- Edit the scheme to add command-line arguments (`../../resources`) or to run
  in release mode.


Windows Visual Studio 2017
--------------------------

The provided `.sln` should work out of the box.


- To build and run the project, right-click on `Lab3` in the project explorer
  and then click on "Set as Startup Project." Then press F7 (Build Solution)
  and then F5 (Start Debugging).
- To add a commandline argument, right-click on `Lab3` in
  the project explorer and then click on "Properties" and then click on
  "Debugging."


Windows Visual Studio 2015
--------------------------

Or on your own machine, if you would prefer to use CMake.

Use [vcpkg](https://github.com/Microsoft/vcpkg) to install `glfw3` and `glm`.

	> cmake ..

By default on Windows, CMake will generate a Visual Studio solution file,
`Lab00.sln`, which you can open by double-clicking. If you get a version
mismatch, you may have to specify your visual studio version, for example:

	> cmake -G "Visual Studio 14 2015" ..

Other versions of Visual Studio are listed on the CMake page
(<http://cmake.org/cmake/help/latest/manual/cmake-generators.7.html>).

- To build and run the project, right-click on `Lab3` in the project explorer
  and then click on "Set as Startup Project." Then press F7 (Build Solution)
  and then F5 (Start Debugging).
- To add a commandline argument, right-click on `Lab3` in
  the project explorer and then click on "Properties" and then click on
  "Debugging."

