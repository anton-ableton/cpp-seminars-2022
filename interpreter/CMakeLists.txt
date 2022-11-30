cmake_minimum_required(VERSION 3.12)
project(forth)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARN_FLAGS} ${ASAN_OPTIONS} -fsanitize=address")

add_executable(forth command.cpp main.cpp)
