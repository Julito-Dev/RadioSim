cmake_minimum_required(VERSION 3.14)

project(RadioSim VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(reactor-sim
    src/main.cpp
)

target_include_directories(reactor-sim
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
