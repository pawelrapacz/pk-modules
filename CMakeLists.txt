cmake_minimum_required(VERSION 3.31)
project(pk-modules)

set(
    CMAKE_CXX_STANDARD 20
    CMAKE_CXX_STANDARD_REQUIRED ON
    CMAKE_CXX_EXTENSIONS OFF
)

enable_testing()

add_library(modules)

target_sources(modules
PUBLIC
FILE_SET CXX_MODULES TYPE CXX_MODULES
FILES
    src/Complex.ixx
    src/Matrix.ixx
    src/Anonimization.ixx
    src/DateFormats.ixx
)

add_subdirectory(tests)