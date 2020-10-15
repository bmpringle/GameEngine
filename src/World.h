#ifndef WORLD_H
#define WORLD_H
#include<vector>
#include"Tile.h"

class World {
    public:
        World();

        void parseWorld(std::string world);

        void addTile(Tile t);

        std::vector<Tile>* getTilesPointer();

        float getUnitToNormal();

        void renderTiles(int program, int texprogram);
    private:
        std::vector<Tile> tiles = std::vector<Tile>();
        float unitToNormal = 1.0/5.0;

};
#endif