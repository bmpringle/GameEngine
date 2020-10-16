#ifndef WORLD_H
#define WORLD_H
#include<vector>
#include"Tile.h"
#include"Entity.h"
#include<chrono>

class World {
    public:   
        World();

        void parseWorld(std::string world);

        void addTile(Tile t);

        void addEntity(Entity t);

        void addPlayer(Entity e);

        Entity* getPlayer();

        std::vector<Tile>* getTilesPointer();

        std::vector<Entity>* getEntitiesPointer();

        float getUnitToNormal();

        void render(int program, int texprogram);

        Tile* getTilePointer(float x, float y);

        Entity* getEntityPointer(float x, float y);
    private:
        std::vector<Tile> tiles = std::vector<Tile>();
        std::vector<Entity> entities = std::vector<Entity>();
        float unitToNormal = 1.0/5.0;
        Entity player = Entity(0, 0);
};
#endif