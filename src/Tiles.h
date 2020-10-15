#ifndef TILES_H
#define TILES_H
#include"Tile.h"

class Tiles {
    public:
        static std::vector<Tile> tileList;

        //note, if the type doesn't exist a generic tile will be given.
        static Tile getType(std::string type);

        static void tileInit();
};
#endif