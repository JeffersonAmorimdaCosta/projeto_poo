#!/bin/bash

g++ -g --std=c++17 -o game.exe *.cpp ASCII_Engine/*.cpp ASCII_Engine/Core/*.cpp ASCII_Engine/utils/*.cpp src/*.cpp && ./game.exe
