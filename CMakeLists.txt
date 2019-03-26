cmake_minimum_required(VERSION 3.5)

project(ColorConvert)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)