#include"World.h"
#include<fstream>
#include<string.h>
#include<sstream>
#include"Tiles.h"
#include<math.h>

World::World() {
    float player_vertices[] = {
        0.4, 0.15, 0,
        0.6, 0.15, 0,
        0.6, 0.85, 0,
        0.4, 0.15, 0,
        0.4, 0.85, 0,
        0.6, 0.85, 0
    };
    player = Entity(0, 0, "player", player_vertices);
    player.loadTexture("player.png");
    player.world = this;
}

void World::addTile(Tile t) {
    t.world = this;
    tiles.push_back(t);
}

std::vector<Tile>* World::getTilesPointer() {
    return &tiles;
}

float World::getUnitToNormal() {
    return unitToNormal;
}

void World::render(int program, int texprogram) {
    for(Tile tile : tiles) {
        if(tile.hasTexture) {
            tile.render(texprogram, unitToNormal);
        }else {
            tile.render(program, unitToNormal);
        }
    }

    for(Entity entity : entities) {
        if(entity.hasTexture) {
            entity.render(texprogram, unitToNormal);
        }else {
            entity.render(program, unitToNormal);
        }
    }

    float x = player.getX();
    float y = player.getY();
    player.setPos(0, 0);
    if(player.hasTexture) {
        player.render(texprogram, unitToNormal);
    }else {
        player.render(program, unitToNormal);
    }
    player.setPos(x, y);
}

Tile* World::getTilePointer(float x, float y) {
    for(int i=0; i<tiles.size(); ++i) {
        if(tiles[i].getX() == x && tiles[i].getY() == y) {
            return &tiles[i];
        }
    }
    return nullptr;
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
        
        if(result.size() != 0) {
            if(result[0] == "attach") {
                float x = std::stof(result.at(2));
                float y = std::stof(result.at(3));
                int xTile = floor(x);
                int yTile = floor(y);
                float xMod = x-xTile;
                float yMod = y-yTile;

                std::string type = result.at(1);
                Tile t = Tiles::getType(type);          
                t.changePos(xMod, yMod);
                this->getTilePointer(xTile, yTile)->addAttachment(t);
            }else {
                if(result.size() == 2) {
                    int x = std::stoi(result.at(0));
                    int y = std::stoi(result.at(1));
                    std::string type = "generic";
                    Tile t = Tiles::getType(type);
                    t.changePos(x, y);
                    addTile(t);            
                }else {
                    int x = std::stoi(result.at(1));
                    int y = std::stoi(result.at(2));
                    std::string type = result.at(0);
                    Tile t = Tiles::getType(type);
                    t.changePos(x, y);
                    addTile(t);
                }
            }
        }
    }
}

void World::addEntity(Entity t) {
    t.world = this;
    entities.push_back(t);
}

std::vector<Entity>* World::getEntitiesPointer() {
    return &entities;

}

Entity* World::getEntityPointer(float x, float y) {
    for(int i=0; i<entities.size(); ++i) {
        if(entities[i].getX() == x && entities[i].getY() == y) {
            return &entities[i];
        }
    }
    return nullptr;
}

Entity* World::getPlayer() {
    return &player;
}