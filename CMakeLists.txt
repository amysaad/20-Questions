cmake_minimum_required(VERSION 3.23)
project(sourceCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(sourceCode main.cpp constants.h Functions.cpp Functions.h main.cpp Node.cpp Node.h Tree.cpp
        Tree.h)
