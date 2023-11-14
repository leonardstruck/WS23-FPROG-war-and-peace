find_package(range-v3)

add_executable(test test_main.cpp
    tokenize_test.cpp
        ../src/filter.h
        filter_test.cpp
)
target_link_libraries(test range-v3::range-v3)
