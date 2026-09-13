cmake_minimum_required(VERSION 3.16)

project(Laba4Stack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stack_app
    cpp/src/main.cpp
    cpp/src/stack.cpp
)

target_include_directories(stack_app PRIVATE
    cpp/include
)
