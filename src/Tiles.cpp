#include"Tiles.h"

//note, tileList[0] is generic type
std::vector<Tile> Tiles::tileList = std::vector<Tile>();

Tile Tiles::getType(std::string type) {
    for(Tile tile : tileList) {
        if(type == tile.type) {
            return tile;
        }
    }
    return tileList[0];
}

void Tiles::tileInit() {  
    Tile lwall = Tile(0, 0, "lwall");
    lwall.loadTexture("lwall.png");
    lwall.setPermissable(2, false);
    
    Tile twall = Tile(0, 0, "twall");
    twall.loadTexture("twall.png");
    twall.setPermissable(0, false);

    Tile rwall = Tile(0, 0, "rwall");
    rwall.loadTexture("rwall.png");
    rwall.setPermissable(3, false);

    Tile bwall = Tile(0, 0, "bwall");
    bwall.loadTexture("bwall.png");
    bwall.setPermissable(1, false);
    
    Tile blcorner = Tile(0, 0, "blcorner");
    blcorner.setPermissable(1, false);
    blcorner.setPermissable(2, false);
    blcorner.loadTexture("blcorner.png");
    
    Tile brcorner = Tile(0, 0, "brcorner");
    brcorner.setPermissable(1, false);
    brcorner.setPermissable(3, false);
    brcorner.loadTexture("brcorner.png");

    Tile tlcorner = Tile(0, 0, "tlcorner");
    tlcorner.setPermissable(0, false);
    tlcorner.setPermissable(2, false);
    tlcorner.loadTexture("tlcorner.png");

    Tile trcorner = Tile(0, 0, "trcorner");
    trcorner.setPermissable(0, false);
    trcorner.setPermissable(3, false);
    trcorner.loadTexture("trcorner.png");

    Tile generic = Tile(0, 0, "generic");

    Tile table = Tile(0, 0, "table");
    table.setPermissable(0, false);
    table.setPermissable(1, false);
    table.setPermissable(2, false);
    table.setPermissable(3, false);
    table.loadTexture("table.png");

    float mug_vertices[] = {
        0.4, 0.4, 0,
        0.6, 0.4, 0,
        0.6, 0.6, 0,
        0.4, 0.4, 0,
        0.4, 0.6, 0,
        0.6, 0.6, 0
    };

    Tile mug = Tile(0.2, 0.2, "mug", mug_vertices);
    mug.setPos(0, 0, -2);
    mug.setPermissable(0, false);
    mug.setPermissable(1, false);
    mug.setPermissable(2, false);
    mug.setPermissable(3, false);
    mug.loadTexture("mug.png");

    tileList.push_back(generic);

    tileList.push_back(lwall);
    tileList.push_back(twall);
    tileList.push_back(rwall);
    tileList.push_back(bwall);
    tileList.push_back(blcorner);
    tileList.push_back(brcorner);
    tileList.push_back(tlcorner);
    tileList.push_back(trcorner);

    tileList.push_back(table);
    tileList.push_back(mug);
}