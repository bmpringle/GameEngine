#ifndef TILE_H
#define TILE_H
#include<vector>
#include<GL/glew.h>
#include<iostream>
#include"Init.h"
#include<functional>
#include<chrono>

class Entity;
class World;

class Tile {
    public:
        World* world;

        std::string type = "generic";

        Tile(float _x, float _y);

        Tile(float _x, float _y, std::vector<float> _vertices);

        Tile(float _x, float _y, std::string type);

        Tile(float _x, float _y, std::string type, std::vector<float> _vertices);

        void loadTexture(std::string asset);

        void loadTexture(unsigned char* data, int width, int height, int nrChannels);

        void unloadTexture();

        void render(int program, float unitsToNormal);

        void render(int program, float unitsToNormal, float _x, float _y);

        void renderAttachments(int program, float unitsToNormal, int _x, int _y);

        void setPos(float _x, float _y);

        void setPos(float _x, float _y, float _z);

        float getX();

        float getY();

        float getZ();

        void changePos(float xUnits, float yUnits);

        void changePos(float xUnits, float yUnits, float zUnits);

        bool hasTexture = false;

        enum E_DIRECTION {
            EDIR_UP     = 0,
            EDIR_DOWN   = 1,
            EDIR_LEFT   = 2,
            EDIR_RIGHT  = 3,
            EDIR_NUM    = 4
        };

        /*
        parameters: 
            E_DIRECTION direction:
            bool option:
                true: permissable
                false: not permissable
        */
        void setPermissable(E_DIRECTION direction, bool option);

        /*
        parameters: 
            E_DIRECTION direction:
        return:    
            bool:
                true: permissable
                false: not permissable
        */
        bool getPermissable(E_DIRECTION direction);

        void setType(std::string _type);

        void addAttachment(Tile a);

        void showAttachmentOnInteractionTimed(Tile a, float time);

        void showAndHideAttachmentOnInteraction(Tile a);

        std::vector<Tile>* getAttachments();

        void interactionOn(Entity* e);

        void update();

        void showAndHideTextBoxOnInteraction(std::string text);

        void setUV(std::vector<float> uvIn);

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
        std::vector<float> vertices = std::vector<float>();
        std::vector<float> uv = std::vector<float>();

        std::vector<Tile> attachments = std::vector<Tile>();

        //size should never be greater than 1. vector is used as a wrapper to allow a tile to be in a tile.
        std::vector<Tile> attachementToShowOnInteractionTimed = std::vector<Tile>();
        float timeToShow = 0;
        bool showInterAttachTimed = false;
        std::chrono::system_clock::time_point start_interaction_show_timer = std::chrono::system_clock::now();

        //size should never be greater than 1. vector is used as a wrapper to allow a tile to be in a tile.
        std::vector<Tile> attachementToShowAndHideOnInteraction = std::vector<Tile>();
        bool showInterAttach = false;
        std::chrono::system_clock::time_point start_buffer_show_timer = std::chrono::system_clock::now();

        //used to hold textboxbehavior
        std::string interactionText = "";
        bool hasTextBoxInteractionBehavior = false;
        std::chrono::system_clock::time_point start_interaction_textbox_close_timer = std::chrono::system_clock::now();

    private:
        
};
#endif