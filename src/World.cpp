#include"World.h"
#include<fstream>
#include<string.h>
#include<sstream>
#include<math.h>

void createCharacters(std::vector<Character>* characters) {
    characters->push_back(Character({0, 52, 40, 52, 40, 10, 0, 52, 0, 10, 40, 10}, "A", false));
    characters->push_back(Character({45, 52, 76, 52, 76, 10, 45, 52, 45, 10, 76, 10}, "B", false));
    characters->push_back(Character({82, 52, 117, 52, 117, 10, 82, 52, 82, 10, 117, 10}, "C", false));
    characters->push_back(Character({125, 52, 162, 52, 162, 10, 125, 52, 125, 10, 162, 10}, "D", false));
    characters->push_back(Character({170, 52,  198, 52,  198, 10, 170, 52, 170, 10,  198, 10}, "E", false));
    characters->push_back(Character({207, 52,  232, 52,  232, 10, 207, 52, 207, 10,  232, 10}, "F", false));
    characters->push_back(Character({238, 52,  275, 52,  275, 10, 238, 52, 238, 10,  275, 10}, "G", false));
    characters->push_back(Character({285, 52,  318, 52,  318, 10, 285, 52, 285, 10,  318, 10}, "H", false));
    characters->push_back(Character({329, 52,  336, 52,  336, 10, 329, 52, 329, 10,  336, 10}, "I", false));
    characters->push_back(Character({338, 64,  353, 64,  353, 10, 338, 64, 338, 10,  353, 10}, "J", false));
    characters->push_back(Character({363, 52,  397, 52,  397, 10, 363, 52, 363, 10,  397, 10}, "K", false));
    characters->push_back(Character({401, 52,  428, 52,  428, 10, 401, 52, 401, 10,  428, 10}, "L", false));
    characters->push_back(Character({433, 52,  473, 52,  473, 10, 433, 52, 433, 10,  473, 10}, "M", false));
    characters->push_back(Character({483, 52,  516, 52,  516, 10, 483, 52, 483, 10,  516, 10}, "N", false));
    characters->push_back(Character({524, 52,  564, 52,  564, 10, 524, 52, 524, 10,  564, 10}, "O", false));
    characters->push_back(Character({572, 52,  600, 52,  600, 10, 572, 52, 572, 10,  600, 10}, "P", false));
    characters->push_back(Character({605, 59,  645, 59,  645, 10, 605, 59, 605, 10,  645, 10}, "Q", false));
    characters->push_back(Character({653, 52,  687, 52,  687, 10, 653, 52, 653, 10,  687, 10}, "R", false));
    characters->push_back(Character({691, 52,  722, 52,  722, 10, 691, 52, 691, 10,  722, 10}, "S", false));
    characters->push_back(Character({724, 52,  761, 52,  761, 10, 724, 52, 724, 10,  761, 10}, "T", false));
    characters->push_back(Character({765, 52,  798, 52,  798, 10, 765, 52, 765, 10,  798, 10}, "U", false));
    characters->push_back(Character({802, 52,  841, 52,  841, 10, 802, 52, 802, 10,  841, 10}, "V", false));
    characters->push_back(Character({844, 52,  898, 52,  898, 10, 844, 52, 844, 10,  898, 10}, "W", false));
    characters->push_back(Character({902, 52,  937, 52,  937, 10, 902, 52, 902, 10,  937, 10}, "X", false));
    characters->push_back(Character({939, 52,  975, 52,  975, 10, 939, 52, 939, 10,  975, 10}, "Y", false));
    characters->push_back(Character({977, 52,  1011, 52,  1011, 10, 977, 52, 977, 10,  1011, 10}, "Z", false));

    characters->push_back(Character({3, 121, 30, 121, 30, 76, 3, 121, 3, 76, 30, 76}, "a", true));
    characters->push_back(Character({41, 121, 70, 121, 70, 76, 41, 121, 41, 76, 70, 76}, "b", true));
    characters->push_back(Character({76, 121, 102, 121, 102, 76, 76, 121, 76, 76, 102, 76}, "c", true));
    characters->push_back(Character({108, 121, 136, 121, 136, 76, 108, 121, 108, 76, 136, 76}, "d", true));
    characters->push_back(Character({145, 121, 175, 121, 175, 76, 145, 121, 145, 76, 175, 76}, "e", true));
    characters->push_back(Character({176, 121, 200, 121, 200, 76, 176, 121, 176, 76, 200, 76}, "f", true));
    characters->push_back(Character({201, 131, 229, 131, 229, 76, 201, 131, 201, 76, 229, 76}, "g", true));
    characters->push_back(Character({240, 121, 266, 121, 266, 76, 240, 121, 240, 76, 266, 76}, "h", true));
    characters->push_back(Character({269, 121, 292, 121, 292, 76, 269, 121, 269, 76, 292, 76}, "i", true));
    characters->push_back(Character({283, 131, 308, 131, 308, 76, 283, 131, 283, 76, 308, 76}, "j", true));
    characters->push_back(Character({309, 121, 337, 121, 337, 76, 309, 121, 309, 76, 337, 76}, "k", true));
    characters->push_back(Character({338, 121, 358, 121, 358, 76, 338, 121, 338, 76, 358, 76}, "l", true));
    characters->push_back(Character({358, 121, 406, 121, 406, 76, 358, 121, 358, 76, 406, 76}, "m", true));
    characters->push_back(Character({416, 121, 442, 121, 442, 76, 416, 121, 416, 76, 442, 76}, "n", true));
    characters->push_back(Character({451, 121, 480, 121, 480, 76, 451, 121, 451, 76, 480, 76}, "o", true));
    characters->push_back(Character({488, 131, 517, 131, 517, 76, 488, 131, 488, 76, 517, 76}, "p", true));
    characters->push_back(Character({523, 131, 551, 131, 551, 76, 523, 131, 523, 76, 551, 76}, "q", true));
    characters->push_back(Character({562, 121, 580, 121, 580, 76, 562, 121, 562, 76, 580, 76}, "r", true));
    characters->push_back(Character({584, 121, 608, 121, 608, 76, 584, 121, 584, 76, 608, 76}, "s", true));
    characters->push_back(Character({611, 121, 632, 121, 632, 76, 611, 121, 611, 76, 632, 76}, "t", true));
    characters->push_back(Character({638, 121, 665, 121, 665, 76, 638, 121, 638, 76, 665, 76}, "u", true));
    characters->push_back(Character({672, 121, 703, 121, 703, 76, 672, 121, 672, 76, 703, 76}, "v", true));
    characters->push_back(Character({707, 121, 749, 121, 749, 76, 707, 121, 707, 76, 749, 76}, "w", true));
    characters->push_back(Character({753, 121, 784, 121, 784, 76, 753, 121, 753, 76, 784, 76}, "x", true));
    characters->push_back(Character({787, 131, 818, 131, 818, 76, 787, 131, 787, 76, 818, 76}, "y", true));
    characters->push_back(Character({821, 121, 847, 121, 847, 76, 821, 121, 821, 76, 847, 76}, "z", true));

    characters->push_back(Character({850, 121, 870, 121, 870, 76, 850, 121, 850, 76, 870, 76}, ".", false));
    characters->push_back(Character({870, 121, 880, 121, 880, 76, 870, 121, 870, 76, 880, 76}, "!", false));
    characters->push_back(Character({890, 126, 910, 126, 910, 76, 890, 126, 890, 76, 910, 76}, ",", false));
    characters->push_back(Character({913, 121, 935, 121, 935, 76, 913, 121, 913, 76, 935, 76}, "?", false));
    characters->push_back(Character({940, 121, 970, 121, 970, 76, 940, 121, 940, 76, 970, 76}, "\"", false));
}

World::World() : hud(0.0f, this) {
    std::vector<float> player_vertices = {
        0.4, 0.15, 0,
        0.6, 0.15, 0,
        0.6, 0.85, 0,
        0.4, 0.15, 0,
        0.4, 0.85, 0,
        0.6, 0.85, 0
    };

    hud = HUD(unitToNormal, this);
    player = Entity(0, 0, "player", player_vertices);
    player.loadTexture("player.png");
    player.world = this;

    createCharacters(&characters);

    char letter = 'A';

    for(int i = 0; i<26; ++i) {
        lettersToNumbers.insert(std::make_pair(letter, i));
        letter = (char)((int)letter + 1);
    }

    letter = 'a';
    for(int i = 26; i<52; ++i) {
        lettersToNumbers.insert(std::make_pair(letter, i));
        letter = (char)((int)letter + 1);
    }
    lettersToNumbers.insert(std::make_pair('.', 52));
    lettersToNumbers.insert(std::make_pair('!', 53));
    lettersToNumbers.insert(std::make_pair(',', 54));
    lettersToNumbers.insert(std::make_pair('?', 55));
    lettersToNumbers.insert(std::make_pair('"', 56));
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
    
    hud.render(program, texprogram);

    if(showTextbox) {
        renderTextBox(program, texprogram);
    }

    player.setPos(x, y);
}

void World::renderTextBox(int program, int texprogram) {

    for(int i=0; i<textbox.getAttachments()->size(); ++i) {
        textbox.getAttachments()->at(i).changePos(0, this->textOffset);
    }

    if(textbox.hasTexture) {
        textbox.render(texprogram, unitToNormal);
        textbox.renderAttachments(texprogram, unitToNormal, 0, 0);
    }else {
        textbox.render(program, unitToNormal);
        textbox.renderAttachments(program, unitToNormal, 0, 0);
    }

    for(int i=0; i<textbox.getAttachments()->size(); ++i) {
        textbox.getAttachments()->at(i).changePos(0, -this->textOffset);
    }
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
    std::vector<Entity> entityData = std::vector<Entity>();

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
        * command: createEntity
        *   parameters: type(required), vertices(optional)
        * command: setEntityStats:
        *   parameters: entity to set stats of, health(float), str(int), def(int), intel(int) 
        * command: loadEntityTexture
        *   paramters: entity to load to, asset name
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
        * command: spawn
        *   parameters: the name of the entity to spawn, x, y, z, of where to spawn it.
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
                }else {
                    Tile t = Tile(0, 0, type);
                    t.world = this;
                    data.push_back(t);                   
                }
            }else if(lineToks[TOK_CMD] == "createEntity") {
                std::string type = lineToks[TOK_PARAM(0)];
                if(lineToks.size() > 2) {
                    std::vector<float> vertices = std::vector<float>();
                    auto nParams = lineToks.size() - 1;
                    for(int p = 1; p<nParams; ++p) {
                        vertices.push_back(std::stof(lineToks[TOK_PARAM(p)]));
                    }
                    Entity t = Entity(0, 0, type, vertices); 

                    t.setPermissable(Tile::EDIR_UP, false);
                    t.setPermissable(Tile::EDIR_DOWN, false);
                    t.setPermissable(Tile::EDIR_LEFT, false);
                    t.setPermissable(Tile::EDIR_RIGHT, false);

                    entityData.push_back(t);
                } else {
                    Entity t = Entity(0, 0, type);
                    t.world = this;
                    entityData.push_back(t);                   
                }
            }else if(lineToks[TOK_CMD] == "loadEntityTexture") {
                std::string textured = lineToks[TOK_PARAM(0)];
                for(int i=0; i<entityData.size(); ++i) {
                    if(entityData[i].type == textured) {
                        entityData[i].loadTexture(lineToks[TOK_PARAM(1)]);
                    }
                }
            }else if(lineToks[TOK_CMD] == "loadTexture") {
                std::string textured = lineToks[TOK_PARAM(0)];
                for(int i=0; i<data.size(); ++i) {
                    if(data[i].type == textured) {
                        data[i].loadTexture(lineToks[TOK_PARAM(1)]);
                    }
                }
            }else if(lineToks[TOK_CMD] == "setEntityStats") {
                std::string entityName = lineToks[TOK_PARAM(0)];
                float health = std::stof(lineToks[TOK_PARAM(1)]);
                int str = std::stof(lineToks[TOK_PARAM(2)]);
                int def = std::stof(lineToks[TOK_PARAM(3)]);
                int intel = std::stof(lineToks[TOK_PARAM(4)]);

                for(int i=0; i<entityData.size(); ++i) {
                    if(entityData[i].type == entityName) {
                        entityData[i].setStats(health, str, def, intel);
                    }
                }
            }else if(lineToks[TOK_CMD] == "addBehavior") {
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
            }else if(lineToks[TOK_CMD] == "attach") {
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

            }else if(lineToks[TOK_CMD] == "place") {
                Tile p = Tile(0, 0);
                for(Tile t : data) {
                    if(t.type == lineToks[TOK_PARAM(0)]) {
                        p = t;
                    }
                }
                p.setPos(std::stoi(lineToks[TOK_PARAM(1)]), std::stoi(lineToks[TOK_PARAM(2)]));
                if(lineToks.size() == 5) {
                    p.changePos(0, 0, std::stoi(lineToks[TOK_PARAM(3)]));
                }
                addTile(p);
            }else if(lineToks[TOK_CMD] == "spawn") {
                Entity e = Entity(0, 0);
                for(Entity t : entityData) {
                    if(t.type == lineToks[TOK_PARAM(0)]) {
                        e = t;
                    }
                }
                e.setPos(std::stoi(lineToks[TOK_PARAM(1)]), std::stoi(lineToks[TOK_PARAM(2)]));
                if(lineToks.size() == 5) {
                    e.changePos(0, 0, std::stoi(lineToks[TOK_PARAM(3)]));
                }
                addEntity(e);
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
    hud.update(player);
}

void World::showTextBox(std::string text, bool show) {
    textbox.world = this;
    textbox.loadTexture("textbox.png");
    showTextbox = show;
    textDisplayed = text;

    if(show != false) {
        std::vector<Tile>* tiles = textbox.getAttachments();
        tiles = nullptr;

        float size = characters[0].size;

        float spacing = 0.2;

        //size of space - size of a char / 5
        float spaceSize = size*(1+spacing);

        float returnSize = size*(1+spacing);

        float texelOffset = 0.05;

        //calcuating the top-left of the white area of the textbox
        float textBoxBeginningX = -1.0/unitToNormal+(10.0/1024.0)*2.0/unitToNormal;
        float textBoxBeginningY = -1/(unitToNormal)-(10.0/128.0)*1/(unitToNormal*2)+1/(unitToNormal*2)-size-(10.0/128.0)*texelOffset;

        float textBoxLength = 2.0/unitToNormal-(10.0/1024.0)*2.0/unitToNormal-2*size;
        float textBoxEndY = -1/(unitToNormal) + (10.0/128.0)*texelOffset + (10.0/128.0)*1/(unitToNormal*2);

        float i = 0;
        float j = 0;

        bool option = false;

        for(char character : text) {

            if(character != ' ' && character != '\\' && !(option && character == 'n')) {
                int index = lettersToNumbers.at(character);
                Character t = characters[index];
                t.setPos(textBoxBeginningX+i, textBoxBeginningY-j, -5);
                textbox.addAttachment(t);
                if(i >= textBoxLength-size) {
                    i = -spaceSize;
                    j+=returnSize;
                }
                i+=spaceSize;
            }

            if(character == 'n' && option) {
                j+=returnSize;
                i = -spaceSize;
            }

            option = false;
            if(character == '\\') {
                option = true;
            }

            if(character == ' ') {
                if(i >= textBoxLength-size) {
                    i = -spaceSize;
                    j+=returnSize;
                }
                i+=spaceSize;
            }
        }

        std::vector<Tile> validAttachments = std::vector<Tile>();

        float largestYNotAllowed = -9999;

        for(int i=0; i<textbox.getAttachments()->size(); ++i) {
            if(textbox.getAttachments()->at(i).getY()+textOffset >= textBoxEndY && textbox.getAttachments()->at(i).getY()+textOffset <= textBoxBeginningY) {
                validAttachments.push_back(textbox.getAttachments()->at(i));
            }else if(textbox.getAttachments()->at(i).getY()+textOffset <= textBoxBeginningY){
                if(largestYNotAllowed < textbox.getAttachments()->at(i).getY()) {
                    largestYNotAllowed = textbox.getAttachments()->at(i).getY();
                }
            }
        }

        textbox.getAttachments()->clear();
        for(Tile t : validAttachments) {
            textbox.addAttachment(t);
        }

        if(textbox.getAttachments()->size() == 0) {
            showTextBox("", false);
        }

        if(largestYNotAllowed == -9999) {
            yMin = -1/unitToNormal;
        }else {
            yMin = largestYNotAllowed+textOffset;
        }
        yMax = textBoxBeginningY;
    }else {
        textOffset = 0;
        yMin = 0;
        yMax = 0;
        textDisplayed = "";
    }
}

bool World::isShowingTextBox() {
    return showTextbox;
}

void World::cycleTextOffset() {
    textOffset+=(yMax - yMin);
    showTextBox(textDisplayed, true);
}