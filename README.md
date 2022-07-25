# Mojave Chess engine
## Welcome
This is a chess engine written by me Oxyn in c++. It is a combination of many chess programming techniques.

Note: Currently, this software is linux exclusive as it relies on Gnu c compiler inbuilt funcitons, this is because linux
this is because linux is my devolopment enviroment eventually ill port it to windows.

The majority of useful doucmentation including a changelog and a todo list for features to be implemented 
into the project can be found in the docs folder.

- [Todo list](https://github.com/Oxyn4/Mojave-Chess-Engine/blob/master/doc/todo.md)
- [Changelog](https://github.com/Oxyn4/Mojave-Chess-Engine/blob/master/doc/changelog.md)

## Compilation 

### Compiling main binary

Mojave uses cmake to generate a makefile which can then be used to build Mojave.

The main binary has no dependancies other than the c++ standard library.

However, Mojave does have tests which are dependant [on googletest](https://github.com/google/googletest)

To compile the Mojave binary:

```sh
    mkdir build
    cd build 
    cmake ..
    make
```
This will build a **mojave** binary under bin/

you can also enable DEBUG mode which useful for debugging.

It outputs extra information as well as enables -g flag for gdb.

To enable compile like:

```sh 
    mkdir build
    cd build
    cmake .. -DDEBUG=ON
    make
```

### Compiling tests

Mojave has tests written with google's [googletest](https://github.com/google/googletest) framework.

This library must be installed to compile Mojaves tests.

To compile and run these tests:

```sh
    mkdir build
    cd build
    cmake .. -DBUILD_TESTS=ON
    make
```

This will compile the tests.

Then to run these tests:

```sh
    ctest
```

### Compiling Benchmark

Mojave has a benchmark written with [hayai](https://github.com/nickbruun/hayai) library.

To build mojave benchmark you must have this library installed.

To build the benchmark:

```sh
    mkdir build
    cd build
    cmake .. -DBUILD_BENCHMARK=ON
    make
```

Then run the benchmark binary under bin/.

```sh
    ./bin/mojave
```

## Usage

To functionaly use mojave you will need another piece of software called a Chess GUI.
This is a program that will provide the interface and filicate interaction with the engine.

Mojave was built with [Chess Arena](http://www.playwitharena.de/) in mind.

## Features
This engine uses many technique outlined on the [Chessprogramming](https://www.chessprogramming.org/Main_Page) wiki for efficency and effectiveness.

### Board Representation
Keeping track of board states:

- Bitboards

### Leaping Piece Move Generation:

leaping pieces use precomputated lookup arrays

- Pawn move & attack generation
- King move & attack generation
- Knight move & attack generation

### Sliding Piece Move generation:

Sliding pieces use the "Classical approach" of a Ray table combined with isolating blocking pieces and a bitscan

- Queen move & attack generation
- Pawn move & attack generation
- Bishop move & attack generation

