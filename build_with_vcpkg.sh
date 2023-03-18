#!/bin/sh

cmake -B build/ -DLOGGING=ON -DBUILD_TESTS=ON -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake

cd build/ 

make

cd ..

