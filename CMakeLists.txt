cmake_minimum_required(VERSION 3.5)

project(console_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(console_game main.cpp creatures.h creatures.cpp functions.h functions.cpp)

target_link_options(console_game PRIVATE -static)
