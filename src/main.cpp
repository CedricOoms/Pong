#include "include.h"
#include "math_3d.h"

GLuint VBO;

static void RenderSceneCB(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_LINES, 0, 2);
    glDisableVertexAttribArray(0);
    glutSwapBuffers();
}

static void CreateVertexBuffer(){
    Vector3f Vertices[2];
    Vertices[0]=Vector3f(-1.0f,-1.0f,0.0f);
    Vertices[1]=Vector3f(1.0f,-1.0f,0.0f);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    }

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(250,100);
    glutCreateWindow("Pong"); 

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);

    CreateVertexBuffer();
    glutDisplayFunc(RenderSceneCB);
    glutMainLoop();

    return 0;
}