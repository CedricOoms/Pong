#include "include.h"
#include "math_3d.h"

unsigned int BufferDot;
unsigned int BufferLeft;
unsigned int BufferRight;

glGenBuffers(1, &BufferDot);
glGenBuffers(2, &BufferLeft);
glGenBuffers(3, &BufferRight);

float dot[2] = {0.0f, 0.0f};
static float BarLeft[4] = {-1.0f, -1.0f, -1.0f, 1.0f};
static float BarRight[4] = {1.0f, -1.0f, 1.0f, 1.0f};

static void CreateVertexBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER, BufferDot);
    glBufferData(GL_ARRAY_BUFFER, sizeof(dot), dot, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, BufferLeft);
    glBufferData(GL_ARRAY_BUFFER, sizeof(BarLeft), BarLeft, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, BufferRight);
    glBufferData(GL_ARRAY_BUFFER, sizeof(BarRight), BarRight, GL_STATIC_DRAW);
    }

static void RenderSceneCB(){
    glClear(GL_COLOR_BUFFER_BIT);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);
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