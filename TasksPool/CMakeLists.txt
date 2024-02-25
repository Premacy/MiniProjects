cmake_minimum_required(VERSION 2.6)
project(ThreadPoolLib)

include_directories("Headers")
include_directories("Sources")

set(HEADERS Headers/TaskPool.h Headers/TaskPool.h Headers/ITask.h)
set(SOURCES Sources/TaskPool.cpp Sources/ThreadTaskSolver.cpp)

add_library(lib ${SOURCES} ${HEADERS})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
