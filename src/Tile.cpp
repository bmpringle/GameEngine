#include"Tile.h"

Tile::Tile(float _x, float _y) {
    x = _x;
    y = _y;
    initVAO();
}

void Tile::render(int program, float unitsToNormal) {
    float vertices[] = {
        0, 0, 0,
        1, 0, 0,
        1, 1, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0
    };

    float colors[] = {
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1            
    };

    for(int i = 0; i<18; i+=3) {
        vertices[i] = vertices[i]+x;
        vertices[i+1] = vertices[i+1]+y;
    }

    for(int i = 0; i<18; ++i) {
        vertices[i] = vertices[i]*unitsToNormal;
    }

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBOV);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBOC);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_DYNAMIC_DRAW);

    glUseProgram(program);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Tile::initVAO() {
    std::vector<unsigned int> VAOarray = allocateVAO();
    VAO = VAOarray[0];
    VBOV = VAOarray[1];
    VBOC = VAOarray[2];
}