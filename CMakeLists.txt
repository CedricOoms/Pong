cmake_minimum_required(VERSION 3.0.0)
project(Pong VERSION 1.0.0)

add_executable(Pong src/main.cpp)

target_link_libraries(Pong GL glfw3 GLEW)

