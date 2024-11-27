cmake_minimum_required(VERSION 3.26)
project(LoginSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LoginSystem main.cpp
        Logging.h Logging.cpp
        LogLevel.h)
