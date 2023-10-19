# My Cpp libraries

### Table of Contents
- [Folder and file structure](#folder-and-file-structure)
- [How to compile the libraries](#how-to-compile-the-libraries)
- [How to use it for the first time](#how-to-use-it-for-the-first-time)

In this repository I'm saving all the useful functions that I write divided into libraries.
I usually find myself writing the same functions the same way over and over in many projects. I decided to make a github repo to import whenever needed in the form of a submodule.
Having to write them only once, I try to make them as general as possible using template functions and avoiding __ANY__ dependencies other than the most common C++ headers.

<a name="folder-and-file-structure"></a>
#### Folder and file structure
The folder structure is as follows:
- include: for File.h
- src: for File.cpp
- lib: for libFile.a
- build: used by cmake, contains the make file

NOTE: For each libFile.a there is just one File.h and one File.cpp

<a name="how-to-compile-the-libraries"></a>
#### How to compile the libraries
To generate the make file execute in the same directory of this README:
```
cmake -S . -B ./build/
```

To compile libraries execute in the same directory of this README:
```
make -C ./build
```

<a name="how-to-use-it-for-the-first-time"></a>
#### How to use it for the first time
Just download the repo and compile the libraries:
```
$ git clone https://github.com/NicoloSalimbeni/My_Cpp_libraries.git
$ cd My_Cpp_libraries/
$ cmake -S . -B ./build/
$ make -C ./build
```
Basicaly clone the repo, get in its directory and than compile the libraries. Now you're good to go with both heather in the include folder and the libraries in the lib folder
