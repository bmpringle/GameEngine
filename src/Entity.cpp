#include"Entity.h"
#include<math.h>
#include"World.h"

Entity::Entity(float _x, float _y) : Tile(_x, _y) {
    rBase = 0;
    gBase = 0;
    bBase = 0;
    z = -1;
}

Entity::Entity(float _x, float _y, std::string type) : Tile(_x, _y, type) {
    rBase = 0;
    gBase = 0;
    bBase = 0;
    z = -1;
}

Entity::Entity(float _x, float _y, float* _vertices) : Tile(_x, _y) {
    rBase = 0;
    gBase = 0;
    bBase = 0;
    z = -1;

    for(int i=0; i<18; ++i) {
        vertices[i] = _vertices[i];
    }
}

Entity::Entity(float _x, float _y, std::string type, float* _vertices) : Tile(_x, _y, type) {
    rBase = 0;
    gBase = 0;
    bBase = 0;
    z = -1;
    for(int i=0; i<18; ++i) {
        vertices[i] = _vertices[i];
    }
}

bool Entity::move(int mode) {
    float modX;
    float modY;
    Tile* tile;

    switch(mode) {
        case 0:
            modX = floor(x);
            modY = floor(y+1);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(1)) {
                    ++y;
                }
                return tile->getPermissable(1);
            }else {
                return false;
            }
        case 1:
            modX = floor(x);
            modY = floor(y-1);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(0)) {
                    --y;
                }
                return tile->getPermissable(0);
            }else {
                return false;
            }
        case 2:
            modX = floor(x-1);
            modY = floor(y);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(3)) {
                    --x;
                }
                return tile->getPermissable(3);
            }else {
                return false;
            }
        case 3:
            modX = floor(x+1);
            modY = floor(y);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(2)) {
                    ++x;
                }
                return tile->getPermissable(2);
            }else {
                return false;
            }
        default:
            return false;
    }
}