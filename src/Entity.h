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
            int mode:
                0: move up
                1: move down
                2: move left
                3: move right
        return:
            bool:
                true: move succesful
                false: move failed
        */
        bool move(int mode);

        void interact();

    private:
};
#endif