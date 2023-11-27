set(CMAKE_CXX_STANDARD 20)

add_executable(
    test test_main.cpp
    process_test.cpp
    tokenizer_test.cpp
    counter_test.cpp
    validator_test.cpp
    filter_test.cpp
        ../src/density_metrics.h
        density_metrics_test.cpp
)

include_directories(../include)