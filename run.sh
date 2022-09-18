#!/bin/bash

if [[ $1 == "Release" ]]; then
    ./build/Release/raylib_mandelbrot
else 
    ./build/Debug/raylib_mandelbrot
fi
