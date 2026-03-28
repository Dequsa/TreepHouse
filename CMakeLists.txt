cmake_minimum_required(VERSION 4.0)
project(TreapHouse)

set(CMAKE_CXX_STANDARD 20)

add_executable(TreapHouse main.cpp
        main.h
        Node.cpp
        Node.h
        Tree.cpp
        Tree.h
        InputHandler.cpp
        InputHandler.h)
