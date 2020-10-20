#include"World.h"
#include<fstream>
#include<string.h>
#include<sstream>
#include"Tiles.h"
#include<math.h>

void createCharacters(std::vector<Character>* characters) {
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "A"));
    characters->push_back(Character({45, 52, 76, 52, 76, 10, 45, 52, 45, 10, 76, 10}, "B"));
    characters->push_back(Character({82, 52, 117, 52, 117, 10, 82, 52, 82, 10, 117, 10}, "C"));
    characters->push_back(Character({125, 52, 162, 52, 162, 10, 125, 52, 125, 10, 162, 10}, "D"));
    characters->push_back(Character({170, 52,  198, 52,  198, 10, 170, 52, 170, 10,  198, 10}, "E"));
    characters->push_back(Character({207, 52,  232, 52,  232, 10, 207, 52, 207, 10,  232, 10}, "F"));
    characters->push_back(Character({238, 52,  275, 52,  275, 10, 238, 52, 238, 10,  275, 10}, "G"));
    characters->push_back(Character({285, 52,  318, 52,  318, 10, 285, 52, 285, 10,  318, 10}, "H"));
    characters->push_back(Character({329, 52,  336, 52,  336, 10, 329, 52, 329, 10,  336, 10}, "I", {3.0/8, 0, 0, 5.0/8, 0, 0, 5.0/8, 1, 0, 3.0/8, 0, 0, 3.0/8, 1, 0, 5.0/8, 1, 0}));
    characters->push_back(Character({338, 64,  353, 64,  353, 10, 338, 64, 338, 10,  353, 10}, "J", {2.0/8, 0, 0, 6.0/8, 0, 0, 6.0/8, 1, 0, 2.0/8, 0, 0, 2.0/8, 1, 0, 6.0/8, 1, 0}));
    characters->push_back(Character({363, 52,  397, 52,  397, 10, 363, 52, 363, 10,  397, 10}, "K"));
    characters->push_back(Character({401, 52,  428, 52,  428, 10, 401, 52, 401, 10,  428, 10}, "L"));
    characters->push_back(Character({433, 52,  473, 52,  473, 10, 433, 52, 433, 10,  473, 10}, "M"));
    characters->push_back(Character({483, 52,  516, 52,  516, 10, 483, 52, 483, 10,  516, 10}, "N"));
    characters->push_back(Character({524, 52,  564, 52,  564, 10, 524, 52, 524, 10,  564, 10}, "O"));
    characters->push_back(Character({572, 52,  600, 52,  600, 10, 572, 52, 572, 10,  600, 10}, "P"));
    characters->push_back(Character({605, 59,  645, 59,  645, 10, 605, 59, 605, 10,  645, 10}, "Q"));
    characters->push_back(Character({653, 52,  687, 52,  687, 10, 653, 52, 653, 10,  687, 10}, "R"));
    characters->push_back(Character({691, 52,  722, 52,  722, 10, 691, 52, 691, 10,  722, 10}, "S"));
    characters->push_back(Character({724, 52,  761, 52,  761, 10, 724, 52, 724, 10,  761, 10}, "T"));
    characters->push_back(Character({765, 52,  798, 52,  798, 10, 765, 52, 765, 10,  798, 10}, "U"));
    characters->push_back(Character({802, 52,  841, 52,  841, 10, 802, 52, 802, 10,  841, 10}, "V"));
    characters->push_back(Character({844, 52,  898, 52,  898, 10, 844, 52, 844, 10,  898, 10}, "W"));
    characters->push_back(Character({902, 52,  937, 52,  937, 10, 902, 52, 902, 10,  937, 10}, "X"));
    characters->push_back(Character({939, 52,  975, 52,  975, 10, 939, 52, 939, 10,  975, 10}, "Y"));
    characters->push_back(Character({977, 52,  1011, 52,  1011, 10, 977, 52, 977, 10,  1011, 10}, "Z"));

    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "a"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "b"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "c"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "d"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "e"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "f"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "g"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "h"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "i"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "j"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "k"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "l"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "m"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "n"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "o"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "p"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "q"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "r"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "s"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "t"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "u"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "v"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "w"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "x"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "y"));
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "z"));
}

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

    createCharacters(&characters);
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
    if(showTextbox) {
        if(textbox.hasTexture) {
            textbox.render(texprogram, unitToNormal);
            textbox.renderAttachments(texprogram, unitToNormal, 0, 0);
        }else {
            textbox.render(program, unitToNormal);
            textbox.renderAttachments(program, unitToNormal, 0, 0);
        }
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
        *           showAttachmentOnInteractionTimed:
        *               attachment to show, time to show for, x, y, z offset for the attachee
        *           showAndHideAttachmentOnInteraction:
        *               attachment to show, x, y, z offset for the attachee
        *           showAndHideTextBoxOnInteraction:
        *               text to show
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
                    Tile::E_DIRECTION direction = Tile::EDIR_UP;
                    if(nsew == "up") {
                        direction = Tile::EDIR_UP;
                    }
                    if(nsew == "down") {
                        direction =  Tile::EDIR_DOWN;
                    }
                    if(nsew == "left") {
                        direction = Tile::EDIR_LEFT;
                    }
                    if(nsew == "right") {
                        direction = Tile::EDIR_RIGHT;
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
                }else if(behavior == "showAttachmentOnInteractionTimed"){
                    std::string attachment = lineToks[3];
                    float timeToShowFor = std::stof(lineToks[4]);
                    float x = std::stof(lineToks[5]);
                    float y = std::stof(lineToks[6]);
                    float z = std::stof(lineToks[7]);

                    Tile a = Tile(0, 0);

                    for(Tile t : data) {
                        if(t.type == attachment) {
                            a = t;
                        }
                    }

                    a.setPos(x, y, z);

                    for(int i=0; i<data.size(); ++i) {
                        if(data[i].type == tileName) {
                            data[i].showAttachmentOnInteractionTimed(a, timeToShowFor);
                        }
                    }
                }else if(behavior == "showAndHideAttachmentOnInteraction"){
                    std::string attachment = lineToks[3];
                    float x = std::stof(lineToks[4]);
                    float y = std::stof(lineToks[5]);
                    float z = std::stof(lineToks[6]);

                    Tile a = Tile(0, 0);

                    for(Tile t : data) {
                        if(t.type == attachment) {
                            a = t;
                        }
                    }

                    a.setPos(x, y, z);

                    for(int i=0; i<data.size(); ++i) {
                        if(data[i].type == tileName) {
                            data[i].showAndHideAttachmentOnInteraction(a);
                        }
                    }
                }else if(behavior == "showAndHideTextBoxOnInteraction"){
                    std::string text = "";

                    for(int i=3; i<lineToks.size(); ++i) {
                        text = text + lineToks[i] + " ";
                    }

                    for(int i=0; i<data.size(); ++i) {
                        if(data[i].type == tileName) {
                            data[i].showAndHideTextBoxOnInteraction(text);
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

void World::update() {
    for(int i=0; i<tiles.size(); ++i) {
        tiles[i].update();
    }

    for(int i=0; i<entities.size(); ++i) {
        entities[i].update();
    }
    player.update();
}

void World::toggleTextBox(std::string text) {
    textbox.world = this;
    textbox.loadTexture("textbox.png");
    showTextbox = !showTextbox;

    std::vector<Tile>* tiles = textbox.getAttachments();
    tiles = nullptr;

    float i = 0;
    float j = 0;

    bool option = false;

    for(char character : text) {

        if(character != ' ' && character != '\\' && !(option && character == 'n')) {
            int index = toggleTextHelper(character);
            Character t = characters[index];
            t.setPos(-4.76+i, -3.3-j, -5);
            textbox.addAttachment(t);
            if(i >= 9) {
                i = -0.4;
                j+=0.4;;
            }
            i+=0.4;
        }

        if(character == 'n' && option) {
            j+=0.4;
            i = -0.4;
        }

        option = false;
        if(character == '\\') {
            option = true;
        }

        if(character == ' ') {
            if(i >= 9) {
                i = -0.4;
                j+=0.4;;
            }
            i+=0.4;
        }
    }
}

bool World::isShowingTextBox() {
    return showTextbox;
}

int World::toggleTextHelper(char character) {
    switch(character) {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        case 'E':
            return 4;
        case 'F':
            return 5;
        case 'G':
            return 6;
        case 'H':
            return 7;
        case 'I':
            return 8;
        case 'J':
            return 9;
        case 'K':
            return 10;
        case 'L':
            return 11;
        case 'M':
            return 12;
        case 'N':
            return 13;
        case 'O':
            return 14;
        case 'P':
            return 15;
        case 'Q':
            return 16;
        case 'R':
            return 17;
        case 'S':
            return 18;
        case 'T':
            return 19;
        case 'U':
            return 20;
        case 'V':
            return 21;
        case 'W':
            return 22;
        case 'X':
            return 23;
        case 'Y':
            return 24;
        case 'Z':
            return 25;
        case 'a':
            return 26;
        case 'b':
            return 27;
        case 'c':
            return 28;
        case 'd':
            return 29;
        case 'e':
            return 30;
        case 'f':
            return 31;
        case 'g':
            return 32;
        case 'h':
            return 33;
        case 'i':
            return 34;
        case 'j':
            return 35;
        case 'k':
            return 36;
        case 'l':
            return 37;
        case 'm':
            return 38;
        case 'n':
            return 39;
        case 'o':
            return 40;
        case 'p':
            return 41;
        case 'q':
            return 42;
        case 'r':
            return 43;
        case 's':
            return 44;
        case 't':
            return 45;
        case 'u':
            return 46;
        case 'v':
            return 47;
        case 'w':
            return 48;
        case 'x':
            return 49;
        case 'y':
            return 50;
        case 'z':
            return 51;
    }
    return 0;
}