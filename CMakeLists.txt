cmake_minimum_required(VERSION 3.12)
project(cppSocketWrapper)

set(CMAKE_CXX_STANDARD 14)

find_package (Threads)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -DDEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(cppSocketWrapper main.cpp src/TCP_Socket.cpp src/TCP_Socket.h src/TCP_Server.cpp src/TCP_Server.h)

target_link_libraries (cppSocketWrapper ${CMAKE_THREAD_LIBS_INIT})