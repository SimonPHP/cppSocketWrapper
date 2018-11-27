cmake_minimum_required(VERSION 3.12)
project(cppSocketWrapper)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppSocketWrapper main.cpp TCP_Socket.cpp TCP_Socket.h)