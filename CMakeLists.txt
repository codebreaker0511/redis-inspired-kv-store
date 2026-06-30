cmake_minimum_required(VERSION 3.10)

project(redis_clone)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(redis_clone
    src/main.cpp
    src/database.cpp
    src/parser.cpp
    src/commands.cpp
    src/server.cpp
)

target_link_libraries(redis_clone ws2_32)