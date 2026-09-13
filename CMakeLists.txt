cmake_minimum_required(VERSION 3.16)

project(Laba4Stack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

#Основная программа
add_executable(stack_app
    cpp/src/main.cpp
    cpp/src/stack.cpp
)

target_include_directories(stack_app PRIVATE
    cpp/include
)

#GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

#Тесты
add_executable(stack_tests
    cpp/tests/test_stack.cpp
    cpp/src/stack.cpp
)

target_include_directories(stack_tests PRIVATE
    cpp/include
)

target_link_libraries(stack_tests PRIVATE
    GTest::gtest_main
)

enable_testing()

include(GoogleTest)
gtest_discover_tests(stack_tests)
