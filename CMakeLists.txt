cmake_minimum_required(VERSION 4.2)
project(OpenBlock)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG master
)


FetchContent_MakeAvailable(raylib)


add_executable(OpenBlock Sources/main.cpp
        Sources/BlockEngine/BlockData.cpp
        Sources/BlockEngine/BlockData.h)
target_link_libraries(OpenBlock raylib)