#include"World.h"

World::World() {
    
}

void World::addTile(Tile t) {
    tiles.push_back(t);
}

std::vector<Tile>* World::getTilesPointer() {
    return &tiles;
}

float World::getUnitToNormal() {
    return unitToNormal;
}

void World::renderTiles(int program) {
    for(Tile tile : tiles) {
        tile.render(program, unitToNormal);
    }
}