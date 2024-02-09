#ifndef VERTEX_H
#define VERTEX_H

struct Vertex {
    float position[2];
    float color[3];

    void scaleColor(float scalar){
        for (int i = 0; i < 3; ++i){
            color[i] *= scalar;
        }
    }
};

#endif