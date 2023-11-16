find_package(range-v3)

set(CMAKE_CXX_STANDARD 11)

add_executable(test test_main.cpp
    tokenizer_test.cpp
    counter_test.cpp
    filter_test.cpp
)
target_link_libraries(test range-v3::range-v3)
