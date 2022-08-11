cmake_minimum_required(VERSION 3.20)

project(TEST_REST)

add_executable(${PROJECT_NAME} ../test_main.cpp test_rest.cpp)

add_subdirectory(../../src/rest rest)
include_directories(../../src/rest)
target_link_libraries(${PROJECT_NAME} rest)