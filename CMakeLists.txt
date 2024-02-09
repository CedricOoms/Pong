cmake_minimum_required(VERSION 3.0.0)
project(Pong VERSION 1.0.0)

add_executable(Pong src/main.cpp src/shader.cpp)

set(FILE1_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/vertexShader.glsl")
set(FILE2_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src/fragmentShader.glsl")

configure_file(${FILE1_PATH} ${CMAKE_CURRENT_BINARY_DIR}/vertexShader.glsl COPYONLY)
configure_file(${FILE2_PATH} ${CMAKE_CURRENT_BINARY_DIR}/fragmentShader.glsl COPYONLY)

target_link_libraries(Pong GL glfw3 GLEW)

