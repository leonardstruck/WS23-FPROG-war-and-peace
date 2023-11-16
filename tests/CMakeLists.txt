find_package(range-v3)

add_executable(test test_main.cpp
    tokenize_test.cpp
    counter_test.cpp
    filter_test.cpp
)
target_link_libraries(test range-v3::range-v3)
