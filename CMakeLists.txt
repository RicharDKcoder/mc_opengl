cmake_minimum_required(VERSION 3.10.0)
project(main VERSION 0.1.0 LANGUAGES C CXX)

# enable_testing()
include(CTest)

add_subdirectory(src/util)
include_directories(src/util)

add_subdirectory(src/engine)
include_directories(src/engine)

add_subdirectory(src/obj)
include_directories(src/obj)

add_subdirectory(src/game)