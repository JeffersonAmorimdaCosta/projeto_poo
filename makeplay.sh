#!/bin/bash

g++ --std=c++17 -o game.exe *.cpp ASCII_Engine/*.cpp ASCII_Engine/Core/*.cpp ASCII_Engine/utils/*.cpp && ./game.exe
