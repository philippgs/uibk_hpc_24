cmake_minimum_required(VERSION 3.9)

project(assignments C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g3 -Wall -Wextra -pedantic")

find_package(AdaptiveCpp REQUIRED)

add_executable(heat_stencil_1d_sycl heat_stencil_1d_sycl.cpp)
add_sycl_to_target(TARGET heat_stencil_1d_sycl)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(heat_stencil_1d heat_stencil_1d.cpp)
