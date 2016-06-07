file(GLOB SRC_FILES "*.cpp" "*.h")


add_executable(game ${SRC_FILES})

include_directories(game "../coffee")

target_link_libraries(game coffee)
