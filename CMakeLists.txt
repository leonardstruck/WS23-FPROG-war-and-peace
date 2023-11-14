cmake_minimum_required(VERSION 3.26)
project(war_and_peace)

set(CMAKE_CXX_STANDARD 20)
find_package(range-v3)

add_executable(war_and_peace src/main.cpp
        src/tokenizer.cpp)

target_link_libraries(war_and_peace range-v3::range-v3)

add_subdirectory(tests)