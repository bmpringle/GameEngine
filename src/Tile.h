#ifndef TILE_H
#define TILE_H
#include<vector>
#include<GL/glew.h>
#include<iostream>
#include"Init.h"

class World;

class Tile {
    public:
        World* world;

        std::string type = "generic";

        Tile(float _x, float _y);

        Tile(float _x, float _y, std::string type);

        void loadTexture(std::string asset);

        void unloadTexture();

        void render(int program, float unitsToNormal);

        float getX();

        float getY();

        void changePos(float xUnits, float yUnits);

        bool hasTexture = false;

        /*
        parameters: 
            int direction:
                0: up
                1: down
                2: left
                3: right
            bool option:
                true: permissable
                false: not permissable
        */
        void setPermissable(int direction, bool option);


        /*
        parameters: 
            int direction:
                0: up
                1: down
                2: left
                3: right
        return:    
            bool:
                true: permissable
                false: not permissable
        */
        bool getPermissable(int direction);

        void setType(std::string _type) {
            type = _type;
        }

    protected:
        unsigned int VAO;
        unsigned int VBOV, VBOC, VBOT;
        unsigned int TBO;
        void initVAO();
        std::vector<bool> permissable = std::vector<bool>();
        float x;
        float y;
        float z;
        float rBase = 1;
        float gBase = 1;
        float bBase = 1;
        float vertices[18] = {};
};
#endif