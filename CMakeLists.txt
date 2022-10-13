cmake_minimum_required(VERSION 3.22)

set(PROJECT Tester)
set(SOURCE src/main.c)

project(${PROJECT})
add_executable(${PROJECT} ${SOURCE})