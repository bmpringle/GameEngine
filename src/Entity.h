#ifndef ENTITY_H
#define ENTITY_H
#include"Tile.h"
class Entity : public Tile {
    public:

        Entity(float _x, float _y);

        Entity(float _x, float _y, std::string type);

        Entity(float _x, float _y, std::vector<float> _vertices);

        Entity(float _x, float _y, std::string type, std::vector<float> _vertices);
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

        void damage(float dmg);

        float getHealth();

        int getStr();

        int getDef();

        int getIntel();

        void setStats(float health, int str, int def, int intel);

    private:
        float health = 10;
        int str = 1;
        int def = 1;
        int intel = 1; 

        bool moveTileCheck(E_DIRECTION direction);
        bool moveEntityCheck(E_DIRECTION direction);
};
#endif