## Compile Instructions
Ensure directory contains the following files:
```bash
$ ~ ls -hartl
-rw-r--r-- 1 1.4K collect.h
-rw-r--r-- 1 1.9K stacksack.cpp
-rw-r--r-- 1 1021 stacksack.h
-rw-r--r-- 1  15K libGenerate.a
-rw-r--r-- 1 3.9K main.cpp
```
Use the following command to compile and run the program:
```bash
$ ~ g++ --std=c++17 -Wall main.cpp libGenerate.a -o SAK && ./SAK size seed
```
# Learning C++ Project 2
More information about this project to come.
