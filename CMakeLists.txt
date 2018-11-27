cmake_minimum_required(VERSION 3.12)
project(cppSocketWrapper)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppSocketWrapper main.cpp src/TCP_Socket.cpp src/TCP_Socket.h src/TCP_Server.cpp src/TCP_Server.h)