#!/bin/sh

git clone https://github.com/Microsoft/vcpkg.git

./vcpkg/bootstrap-vcpkg.sh -disableMetrics

./vcpkg/vcpkg install



