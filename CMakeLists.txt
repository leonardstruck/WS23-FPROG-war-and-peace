cmake_minimum_required(VERSION 3.26)
project(war_and_peace)

set(CMAKE_CXX_STANDARD 20)
add_executable(war_and_peace src/main.cpp
        src/density_metrics.h)

include_directories(include)
add_subdirectory(tests)