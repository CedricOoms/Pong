cmake_minimum_required(VERSION 3.0.0)
project(pong VERSION 1.0.0)

add_executable(pong src/include.h src/main.cpp)

target_link_libraries(pong GL glut GLEW)

