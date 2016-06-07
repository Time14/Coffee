cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Win32, x64
set(BUILD_TYPE "x64")

project(CoffeeGame)

add_subdirectory("coffee")
add_subdirectory("game")
