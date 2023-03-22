#!/bin/sh

cmake -B build/ -DDEBUG=on -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake

cd build/ 

make 

cd ..

