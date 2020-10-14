#ifndef TILE_H
#define TILE_H
#include<vector>
#include<GL/glew.h>
#include<iostream>
#include"Init.h"

class Tile {
    public:
        Tile(float _x, float _y);

        void loadTexture(std::string asset);

        void unloadTexture();

        void render(int program, float unitsToNormal);

        bool hasTexture = false;
    private:
        float x;
        float y;
        unsigned int VAO;
        unsigned int VBOV, VBOC, VBOT;
        unsigned int TBO;
        void initVAO();
};
#endif