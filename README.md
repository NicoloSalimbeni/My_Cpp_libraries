# My Cpp libraries

In this repository I'm saving all the useful functions that I write divided into libraries.
I usually find myself writing the same functions the same way over and over in many projects. I decided to make a github repo to import whenever needed in the form of a submodule.
Having to write them only once, I try to make them as general as possible using template functions and avoiding __ANY__ dependencies other than the most common C++ headers.

#### Folder and file structure
The folder structure is as follows:
- include: for File.h
- src: for File.cpp
- lib: for libFile.a
- build: used by cmake, contains the make file

NOTE: For each libFile.a there is just one File.h and one File.cpp

#### How to compile the libraries
To generate the make file execute in the same directory of this README:
```
cmake -S . -B ./build/
```

To compile libraries execute in the same directory of this README:
```
make -C ./build
```