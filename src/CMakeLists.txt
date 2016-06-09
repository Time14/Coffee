cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(CoffeeGame)

add_subdirectory("coffee")
add_subdirectory("game")

add_definitions(-DLINUX=0 -DWINDOWS=1 -DMAC=2)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	add_definitions(-DTARGET_OS=0)

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	add_definitions(-DTARGET_OS=1)

	#Win32, x64
	set(BUILD_TYPE "x64")

	elif(${CMAKE_SYSTEM_NAME} STREQUAL "Mac")
	add_definitions(-DTARGET_OS=2)
endif()
