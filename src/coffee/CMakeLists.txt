file(GLOB SRC_FILES "*.cpp" "*.h")

add_library(coffee ${SRC_FILES})

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	include_directories(coffee "/include")
endif()
#OpenGL
find_package("OpenGL" REQUIRED)
if(${OPENGL_FOUND})
	include_directories(coffee ${OPENGL_INCLUDE_DIR})
	target_link_libraries(coffee ${OPENGL_LIBRARIES})
endif()

#SDL2
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	file(GLOB SDL_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2/*.lib)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	find_package("SDL2" REQUIRED)
	if(${SDL_FOUND})
		include_directories(coffee ${SDL2_INCLUDE_DIR})
		target_link_libraries(coffee ${SDL2_LIBRARIES})
	endif()
else()
	message(FATAL_ERROR "A ${CMAKE_SYSTEM_NAME} build is not available, yet!")
endif()

target_link_libraries(coffee ${SDL_LIB_DIR})


#GLEW
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	file(GLOB GLEW_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/GLEW/*.lib)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	find_package("GLEW" REQUIRED)
	if(${GLEW_FOUND})
		include_directories(coffee ${GLEW_INCLUDE_DIR})
		target_link_libraries(coffee ${GLEW_LIBRARIES})
	endif()
else()
	message(FATAL_ERROR "A ${CMAKE_SYSTEM_NAME} build is not available, yet!")
endif()

target_link_libraries(coffee ${GLEW_LIB_DIR})
