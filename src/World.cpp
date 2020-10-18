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
    std::string line;
    std::vector<Tile> data = std::vector<Tile>();

    while(std::getline(ifs, line)) {
        std::vector<std::string> lineToks;
        std::stringstream ssLine (line);
        std::string tok;
        // tokenize line
        while (std::getline(ssLine, tok, ' ') && line != "") {
            if(tok.size() > 0) {
                lineToks.push_back(tok);
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
        // Parse Line

        const unsigned TOK_CMD = 0;
        const auto TOK_PARAM = [](unsigned p) {return (p+1);};
        if(lineToks.size() > 0) {
            if(lineToks[TOK_CMD] == "create") {
                std::string type = lineToks[TOK_PARAM(0)];
                if(lineToks.size() > 2) {
                    std::vector<float> vertices = std::vector<float>();
                    auto nParams = lineToks.size() - 1;
                    for(int p = 1; p<nParams; ++p) {
                        vertices.push_back(std::stof(lineToks[TOK_PARAM(p)]));
                    }
                    Tile t = Tile(0, 0, type, vertices); 
                    data.push_back(t);
                } else {
                    Tile t = Tile(0, 0, type);
                    t.world = this;
                    data.push_back(t);                   
                }
            } else if(lineToks[TOK_CMD] == "loadTexture") {
                std::string textured = lineToks[TOK_PARAM(0)];
                for(int i=0; i<data.size(); ++i) {
                    if(data[i].type == textured) {
                        data[i].loadTexture(lineToks[TOK_PARAM(1)]);
                    }
                }
            } else if(lineToks[TOK_CMD] == "addBehavior") {
                std::string tileName = lineToks[TOK_PARAM(0)];
                std::string behavior = lineToks[TOK_PARAM(1)];
                if(behavior == "permissable") {
                    std::string nsew = lineToks[TOK_PARAM(2)];
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
                    std::string truefalse = lineToks[TOK_PARAM(3)];
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

            } else if(lineToks[TOK_CMD] == "attach") {
                std::string base = lineToks[TOK_PARAM(0)];
                std::string attachee = lineToks[TOK_PARAM(1)];
                std::string tileName = lineToks[TOK_PARAM(2)];
                float x = std::stof(lineToks[TOK_PARAM(3)]);
                float y = std::stof(lineToks[TOK_PARAM(4)]);
                float z = std::stof(lineToks[TOK_PARAM(5)]);

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

            } else if(lineToks[TOK_CMD] == "place") {
                Tile p = Tile(0, 0);
                for(Tile t : data) {
                    if(t.type == lineToks[TOK_PARAM(0)]) {
                        p = t;
                    }
                }
                p.setPos(std::stoi(lineToks[TOK_PARAM(1)]), std::stoi(lineToks[TOK_PARAM(2)]), 0);
                if(lineToks.size() == 5) {
                    p.changePos(0, 0, std::stoi(lineToks[TOK_PARAM(3)]));
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