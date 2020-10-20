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

bool Entity::move(E_DIRECTION direction) {
    float modX;
    float modY;
    Tile* tile;
    Tile* tile1 = world->getTilePointer(x, y);;

    if(world->isShowingTextBox()) {
        return false;
    }

    switch(direction) {
        case EDIR_UP:
            modX = floor(x);
            modY = floor(y+1);
            tile = world->getTilePointer(modX, modY);

            if(tile != nullptr) {
                if(tile->getPermissable(EDIR_DOWN)) {
                    if(tile1 != nullptr) {
                        if(tile1->getPermissable(EDIR_UP)) {
                            ++y;
                        }
                        return tile1->getPermissable(EDIR_UP);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(EDIR_DOWN);
            }else {
                return false;
            }
        case EDIR_DOWN:
            modX = floor(x);
            modY = floor(y-1);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(EDIR_UP)) {
                    if(tile1 != nullptr) {
                        if(tile1->getPermissable(EDIR_DOWN)) {
                            --y;
                        }
                        return tile1->getPermissable(EDIR_DOWN);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(EDIR_UP);
            }else {
                return false;
            }
        case EDIR_LEFT:
            modX = floor(x-1);
            modY = floor(y);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(EDIR_RIGHT)) {
                    if(tile1 != nullptr) {
                        if(tile1->getPermissable(EDIR_LEFT)) {
                            --x;
                        }
                        return tile1->getPermissable(EDIR_LEFT);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(EDIR_RIGHT);
            }else {
                return false;
            }
        case EDIR_RIGHT:
            modX = floor(x+1);
            modY = floor(y);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(EDIR_LEFT)) {
                    if(tile1 != nullptr) {
                        if(tile1->getPermissable(EDIR_RIGHT)) {
                            ++x;
                        }
                        return tile1->getPermissable(EDIR_RIGHT);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(EDIR_LEFT);
            }else {
                return false;
            }
        default:
            return false;
    }
}

void Entity::interact() {
    Tile* t1 = world->getTilePointer(x+1, y);
    Tile* t2 = world->getTilePointer(x-1, y);
    Tile* t3 = world->getTilePointer(x, y+1);
    Tile* t4 = world->getTilePointer(x, y-1);

    if(t1 != nullptr) t1->interactionOn(this);
    if(t2 != nullptr) t2->interactionOn(this);
    if(t3 != nullptr) t3->interactionOn(this);
    if(t4 != nullptr) t4->interactionOn(this);
}