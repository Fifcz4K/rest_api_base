cmake_minimum_required(VERSION 3.20)

project(TEST_SERVER)

add_executable(${PROJECT_NAME} ../test_main.cpp test_server.cpp)

add_subdirectory(../../src/server server)
include_directories(../../src/server)
target_link_libraries(${PROJECT_NAME} server)