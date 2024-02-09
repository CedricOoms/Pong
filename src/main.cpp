#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "vertex.h"
#include "shader.h"

Vertex vertices[] = {
    {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{0.0f, 0.5f}, {0.0f, 0.0f, 1.0f}}
};

void setupBuffer(unsigned int vbo){
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

}

void renderData(Vertex data[], GLFWwindow* window){
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 3, data, GL_STATIC_DRAW);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);
}

void changeColor(Vertex data[], GLFWwindow* window){
    for (int t = 0; t <= 3.14; t += 0.1f){
        for (int i = 0; i < 3; ++i){
            data[i].scaleColor(sin(t));
        }
        renderData(data, window);
    }
}

int main(){
    GLFWwindow* window;

    if (!glfwInit()){
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Pong", NULL, NULL);

    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    unsigned int shader = CreateShader("vertexShader.glsl", "fragmentShader.glsl");
    glUseProgram(shader);

    unsigned int buffer;
    setupBuffer(buffer);


    while (!glfwWindowShouldClose(window)){
        /**renderData(vertices, window);**/
        changeColor(vertices, window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}