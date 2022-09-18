#!/bin/bash

if [[ $1 == "Release" ]]; then
    ./build/Release/raylib_example
else 
    ./build/Debug/raylib_example
fi
