cmake_minimum_required(VERSION 3.22)

set(PROJECT Tester)

set(HEADERS src/bars.h src/config.h)
set(SOURCE src/main.c src/bars.c src/config.c)

project(${PROJECT})
add_executable(${PROJECT} ${SOURCE} ${HEADERS})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT})