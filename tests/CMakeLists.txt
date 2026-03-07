add_executable(tests
    tests.cpp
    complex_test.cpp
    matrix_test.cpp
    anonimization_test.cpp
    dateformat_test.cpp
)

target_include_directories(tests PRIVATE ../doctest)

target_link_libraries(tests PRIVATE modules)

add_test(NAME tests COMMAND tests)