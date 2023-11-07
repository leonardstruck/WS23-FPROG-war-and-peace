cmake_minimum_required(VERSION 3.26)
project(war_and_peace)

set(CMAKE_CXX_STANDARD 20)
find_package(range-v3)

add_executable(war_and_peace src/main.cpp
        src/tokenize.hpp)

target_link_libraries(war_and_peace range-v3::range-v3)

add_executable(test tests/test_main.cpp
        tests/tokenize_test.cpp)
target_link_libraries(test range-v3::range-v3)