#ifndef TILE_H
#define TILE_H
#include<vector>
#include<GL/glew.h>
#include<iostream>
#include"Init.h"
#include<functional>

class Entity;
class World;

class Tile {
    public:
        World* world;

        std::string type = "generic";

        Tile(float _x, float _y);

        Tile(float _x, float _y, float* _vertices);

        Tile(float _x, float _y, std::string type);

        Tile(float _x, float _y, std::string type, float* _vertices);

        void loadTexture(std::string asset);

        void unloadTexture();

        void render(int program, float unitsToNormal);

        void render(int program, float unitsToNormal, float _x, float _y);

        void setPos(float _x, float _y);

        void setPos(float _x, float _y, float _z);

        float getX();

        float getY();

        float getZ();

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

        void setType(std::string _type);

        void addAttachment(Tile a);

        std::vector<Tile>* getAttachments();

        void interactionOn(Entity* e);

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
        std::vector<Tile> attachments = std::vector<Tile>();
        std::function<void(World* world, Entity* e)> interactionFunction = [](World* world, Entity* e) {};
    private:
        
};
#endif