cmake_minimum_required(VERSION 3.4.1)
project(datastructures)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(datastructures ${SOURCES})
