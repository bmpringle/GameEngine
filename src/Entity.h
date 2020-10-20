#ifndef ENTITY_H
#define ENTITY_H
#include"Tile.h"
class Entity : public Tile {
    public:

        Entity(float _x, float _y);

        Entity(float _x, float _y, std::string type);

        Entity(float _x, float _y, float* _vertices);

        Entity(float _x, float _y, std::string type, float* _vertices);
        /*
        parameters: 
            E_DIRECTION direction:
        return:
            bool:
                true: move succesful
                false: move failed
        */
        bool move(E_DIRECTION direction);

        void interact();

    private:
};
#endif