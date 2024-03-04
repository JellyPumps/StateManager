cmake_minimum_required(VERSION 3.10)
project(State_Manager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")

add_library(state_manager STATIC ${SOURCES})

install(DIRECTORY include/ DESTINATION include)

install(TARGETS state_manager
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)
