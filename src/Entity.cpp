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

Entity::Entity(float _x, float _y, std::vector<float> _vertices) : Tile(_x, _y) {
    rBase = 0;
    gBase = 0;
    bBase = 0;
    z = -1;
    vertices = _vertices;
}

Entity::Entity(float _x, float _y, std::string type, std::vector<float> _vertices) : Tile(_x, _y, type) {
    rBase = 0;
    gBase = 0;
    bBase = 0;
    z = -1;
    vertices = _vertices;
}

bool Entity::move(E_DIRECTION direction) {

    

    if(world->isShowingTextBox()) {
        return false;
    }

    if(moveTileCheck(direction)) {
        if(moveEntityCheck(direction)) {
            switch(direction) {
                case EDIR_UP:
                    ++y;
                    return true;
                case EDIR_DOWN:
                    --y;
                    return true;
                case EDIR_LEFT:
                    --x;
                    return true;
                case EDIR_RIGHT:
                    ++x;
                    return true;
                default:
                    return false;
            }
        }else {
            return false;
        }
    }else {
        return false;
    }
}


bool Entity::moveTileCheck(Tile::E_DIRECTION direction) {
    float modX;
    float modY;
    Tile* tile;
    Tile* tile1 = world->getTilePointer(x, y);;

    switch(direction) {
        case Tile::EDIR_UP:
            modX = floor(x);
            modY = floor(y+1);
            tile = world->getTilePointer(modX, modY);

            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_DOWN)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_UP);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_DOWN);
            }else {
                return false;
            }
        case Tile::EDIR_DOWN:
            modX = floor(x);
            modY = floor(y-1);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_UP)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_DOWN);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_UP);
            }else {
                return false;
            }
        case Tile::EDIR_LEFT:
            modX = floor(x-1);
            modY = floor(y);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_RIGHT)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_LEFT);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_RIGHT);
            }else {
                return false;
            }
        case Tile::EDIR_RIGHT:
            modX = floor(x+1);
            modY = floor(y);
            tile = world->getTilePointer(modX, modY);
            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_LEFT)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_RIGHT);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_LEFT);
            }else {
                return false;
            }
        default:
            return false;
    }
}

bool Entity::moveEntityCheck(Tile::E_DIRECTION direction) {
    float modX;
    float modY;
    Tile* tile;
    Tile* tile1 = world->getEntityPointer(x, y);;

    switch(direction) {
        case Tile::EDIR_UP:
            modX = floor(x);
            modY = floor(y+1);
            tile = world->getEntityPointer(modX, modY);

            if(tile == nullptr) {
                return true;
            }

            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_DOWN)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_UP);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_DOWN);
            }else {
                return false;
            }
        case Tile::EDIR_DOWN:
            modX = floor(x);
            modY = floor(y-1);
            tile = world->getEntityPointer(modX, modY);

            if(tile == nullptr) {
                return true;
            }

            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_UP)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_DOWN);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_UP);
            }else {
                return false;
            }
        case Tile::EDIR_LEFT:
            modX = floor(x-1);
            modY = floor(y);
            tile = world->getEntityPointer(modX, modY);

            if(tile == nullptr) {
                return true;
            }

            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_RIGHT)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_LEFT);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_RIGHT);
            }else {
                return false;
            }
        case Tile::EDIR_RIGHT:
            modX = floor(x+1);
            modY = floor(y);
            tile = world->getEntityPointer(modX, modY);

            if(tile == nullptr) {
                return true;
            }

            if(tile != nullptr) {
                if(tile->getPermissable(Tile::EDIR_LEFT)) {
                    if(tile1 != nullptr) {
                        return tile1->getPermissable(Tile::EDIR_RIGHT);
                    }else {
                        return false;
                    }
                }
                return tile->getPermissable(Tile::EDIR_LEFT);
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

void Entity::damage(float dmg) {
    float ehp = health * (1+def/100.0);
    float newEHP = ehp - dmg;
    float newHealth = newEHP/(1+def/100.0);
    health = newHealth;
    if(health < 0) {
        health = 0;
    }
}

float Entity::getHealth() {
    return health;
}

int Entity::getStr() {
    return str;
}

int Entity::getDef() {
    return def;
}

int Entity::getIntel() {
    return intel;
}

float Entity::getMaxHealth() {
    return maxHealth;
}

void Entity::setStats(float health, int str, int def, int intel) {
    this->health = health;
    this->maxHealth = health;
    this->str = str;
    this->def = def;
    this->intel = intel;
}