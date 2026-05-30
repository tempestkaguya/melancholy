#!/bin/bash

rm -r build --force

mkdir -p build && cd build || exit 1

cmake ..
cmake --build .

if [ "$1" = "r" ]; then
   ./vision
fi