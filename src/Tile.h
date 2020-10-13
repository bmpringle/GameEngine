#ifndef TILE_H
#define TILE_H
#include<vector>
#include<GL/glew.h>
#include<iostream>
#include"Init.h"

class Tile {
    public:
        Tile(float _x, float _y);

        void render(int program, float unitsToNormal);
    private:
        float x;
        float y;
        unsigned int VAO;
        unsigned int VBOV, VBOC;

        void initVAO();
};
#endif