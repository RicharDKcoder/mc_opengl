cmake_minimum_required(VERSION 3.10.0)
project(main VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(src/engine)
include_directories(src/engine)
add_subdirectory(src/game)