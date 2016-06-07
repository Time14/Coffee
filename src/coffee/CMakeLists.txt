file(GLOB SRC_FILES "*.cpp" "*.h")

add_library(coffee ${SRC_FILES})

include_directories(coffee "/include")

#OpenGL
find_package("OpenGL" REQUIRED)
if(OPENGL_FOUND)
	include_directories(coffee ${OPENGL_INCLUDE_DIR})
	target_link_libraries(coffee ${OPENGL_LIBRARIES})
endif()

#SDL2
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	file(GLOB SDL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2/*.lib)
else()
	message(FATAL_ERROR "A ${CMAKE_SYSTEM_NAME} build is not available, yet!")
endif()

target_link_libraries(coffee ${SDL_LIB_DIR})


#GLEW
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	file(GLOB GLEW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GLEW/*.lib)
else()
	message(FATAL_ERROR "A ${CMAKE_SYSTEM_NAME} build is not available, yet!")
endif()

target_link_libraries(coffee ${GLEW_LIB_DIR})
