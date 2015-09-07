cmake_minimum_required(VERSION 3.3)
project(ftrace_userevents)

ADD_DEFINITIONS("-std=c11")

file(COPY uprobe.sh DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCE_FILES main.c)
add_executable(ftrace_userevents ${SOURCE_FILES})