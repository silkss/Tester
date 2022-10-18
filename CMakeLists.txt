cmake_minimum_required(VERSION 3.22)

set(PROJECT Tester)

set(HEADERS src/Bars.h src/Config.h src/Tester.h src/Trader.h
	src/Strategies.h
	src/Funcs.h)
			
set(SOURCE src/Main.c src/Bars.c src/Config.c src/Tester.c
	src/Strategies.c
	src/Funcs.c)

project(${PROJECT})

add_executable(${PROJECT} ${SOURCE} ${HEADERS})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT})
