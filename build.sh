#!/bin/bash

if [[ $1 == "Release" ]]; then
    echo "Release Build"
    cmake -S . -B build/Release -G Ninja -DCMAKE_BUILD_TYPE=Release
    cmake --build build/Release
    ln -sf build/Release/compile_commands.json compile_commands.json

elif [[ $1 == "WIN" ]]; then
    echo "Windows Build"

    if [[ $2 == "Release" ]]; then
        echo "Release Build"
        cmake -S . -B build/WIN/Release -G Ninja -DCMAKE_TOOLCHAIN_FILE=toolchain/Windows.cmake -DCMAKE_BUILD_TYPE=Release
        cmake --build build/WIN/Release
        ln -sf build/Release/compile_commands.json compile_commands.json

    else
        echo "Debug Build"
        cmake -S . -B build/WIN/Release -G Ninja -DCMAKE_TOOLCHAIN_FILE=toolchain/Windows.cmake -DCMAKE_BUILD_TYPE=Debug
        cmake --build build/WIN/Release
        ln -sf build/Release/compile_commands.json compile_commands.json

    fi

elif [[ $1 == "clear" ]]; then
    echo "Cleaning Build folder"
    rm -r build/*

else
    echo "Debug Build"
    cmake -S . -B build/Debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
    cmake --build build/Debug
    ln -sf build/Debug/compile_commands.json compile_commands.json
fi
