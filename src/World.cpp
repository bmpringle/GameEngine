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

    for(Tile tile : tiles) {
        if(tile.hasTexture) {
            tile.renderAttachments(texprogram, unitToNormal, 0, 0);
        }else {
            tile.renderAttachments(program, unitToNormal, 0, 0);
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
    
    std::vector<Tile> data = std::vector<Tile>();

    while(std::getline(ifs, str)) {
        std::vector<std::string> result;
        std::stringstream ss (str);
        std::string item;

        while (std::getline(ss, item, ' ') && str != "") {
            if(item.size() > 0) {
                result.push_back(item);
            }
        }
        /*
        * command: create 
        *   parameters: type(required), vertices(optional) 
        * command: loadTexture
        *   paramters: tile to load to, asset name 
        * command: addBehavior
        *   parameters: tile to add to, predefined behaviors with their proper parameters
        *       behaviors:
        *           permissable:
        *               up/down/left/right, true/false 
        * command: attach
        *   parameters: tile to attach to, tile being attached, new tile name, x, y, z offset for the attachee
        * 
        * command: place
        *   paramters: the name of the tile to place, x, y, z, of tile
        */

        if(result.size() > 0) {
            if(result[0] == "create") {
                std::string type = result[1];
                if(result.size() > 2) {
                    std::vector<float> vertices = std::vector<float>();
                    for(int i = 2; i<result.size(); ++i) {
                        vertices.push_back(std::stof(result[i]));
                    }
                    Tile t = Tile(0, 0, type, vertices); 
                    data.push_back(t);
                } else {
                    Tile t = Tile(0, 0, type);
                    t.world = this;
                    data.push_back(t);                   
                }     

            }else if(result[0] == "loadTexture") {
                std::string textured = result[1];
                for(int i=0; i<data.size(); ++i) {
                    if(data[i].type == textured) {
                        data[i].loadTexture(result[2]);
                    }
                }
            }else if(result[0] == "addBehavior") {
                std::string tileName = result[1];

                std::string behavior = result[2];
                if(behavior == "permissable") {
                    std::string nsew = result[3];
                    int direction = 0;
                    if(nsew == "up") {
                        direction = 0;
                    }
                    if(nsew == "down") {
                        direction = 1;
                    }
                    if(nsew == "left") {
                        direction = 2;
                    }
                    if(nsew == "right") {
                        direction = 3;
                    }
                    std::string truefalse = result[4];
                    bool rTrueFalse = false;
                    if(truefalse == "true") {
                        rTrueFalse = true;
                    }else {
                        rTrueFalse = false;
                    }

                    for(int i=0; i<data.size(); ++i) {
                        if(data[i].type == tileName) {
                            data[i].setPermissable(direction, rTrueFalse);
                        }
                    }
                }
            }else if(result[0] == "attach") {
                std::string base = result[1];
                std::string attachee = result[2];
                std::string tileName = result[3];
                float x = std::stof(result[4]);
                float y = std::stof(result[5]);
                float z = std::stof(result[6]);

                Tile t = Tile(0, 0);

                for(Tile t1 : data) {
                    if(t1.type == base) {
                        t = t1;
                    }
                }

                Tile a = Tile(0, 0);

                for(Tile t1 : data) {
                    if(t1.type == attachee) {
                        a = t1;
                    }
                }            

                a.setPos(x, y, z);
                t.type = tileName;
                t.addAttachment(a);
                data.push_back(t);
            }else if(result[0] == "place") {           
                Tile p = Tile(0, 0);
                for(Tile t : data) {
                    if(t.type == result[1]) {
                        p = t;
                    }
                }
                p.setPos(std::stoi(result[2]), std::stoi(result[3]), 0);
                if(result.size() == 5) {
                    p.changePos(0, 0, std::stoi(result[4]));
                }
                addTile(p);
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