#include"World.h"
#include<fstream>
#include<string.h>
#include<sstream>

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

void World::renderTiles(int program, int texprogram) {
    for(Tile tile : tiles) {
        if(tile.hasTexture) {
            tile.render(texprogram, unitToNormal);
        }else {
            tile.render(program, unitToNormal);
        }
    }
}

void World::parseWorld(std::string world) {
    std::ifstream ifs = std::ifstream("src/assets/" + world);

    std::string str;
    
    while(std::getline(ifs, str)) {
        std::vector<std::string> result;
        std::stringstream ss (str);
        std::string item;

        while (std::getline(ss, item, ' ')) {
            result.push_back(item);
        }

        int x = std::stoi(result.at(0));
        int y = std::stoi(result.at(1));
        std::string tex = (result.size() == 3) ? result.at(2) : "";
        
        Tile t = Tile(x, y);
        
        if(tex != "") t.loadTexture(tex);
        addTile(t);
    }
}