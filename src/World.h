#ifndef WORLD_H
#define WORLD_H
#include<vector>
#include"Tile.h"

class World {
    public:
        World();

        void addTile(Tile t);

        std::vector<Tile>* getTilesPointer();

        float getUnitToNormal();

        void renderTiles(int program);
    private:
        std::vector<Tile> tiles = std::vector<Tile>();
        float unitToNormal = 1.0/10.0;

};
#endif