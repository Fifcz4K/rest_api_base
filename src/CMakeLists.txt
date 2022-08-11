cmake_minimum_required(VERSION 3.20)

project(GNIOT)

add_executable(${PROJECT_NAME} main.c)

set(includes
    ./server
    ./rest
)

add_subdirectory(./server server)
add_subdirectory(./rest rest)
include_directories(${includes})

if(WIN32)
    target_link_libraries(
        ${PROJECT_NAME} 
        server
        rest
        libwsock32.a
    )
else()
    target_link_libraries(
        ${PROJECT_NAME} 
        server
        rest
    )
endif()