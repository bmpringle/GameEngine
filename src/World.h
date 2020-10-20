#ifndef WORLD_H
#define WORLD_H
#include<vector>
#include"Tile.h"
#include"Entity.h"
#include<chrono>
#include"Character.h"

class World {
    public:   
        World();

        void parseWorld(std::string world);

        void addTile(Tile t);

        void addEntity(Entity t);

        void addPlayer(Entity e);

        void update();

        Entity* getPlayer();

        std::vector<Tile>* getTilesPointer();

        std::vector<Entity>* getEntitiesPointer();

        float getUnitToNormal();

        void render(int program, int texprogram);

        Tile* getTilePointer(float x, float y);

        Entity* getEntityPointer(float x, float y);

        void toggleTextBox(std::string text);

        bool isShowingTextBox();

    private:
        std::vector<Tile> tiles = std::vector<Tile>();
        std::vector<Entity> entities = std::vector<Entity>();
        float unitToNormal = 1.0/5.0;
        Entity player = Entity(0, 0);

        Tile textbox = Tile(0, 0, "textbox", {-5, -5, -4, 5, -5, -4, 5, -2.5, -4, -5, -5, -4, -5, -2.5, -4, 5, -2.5, -4});
        bool showTextbox = false;
        std::vector<Character> characters = std::vector<Character>();

        int toggleTextHelper(char character);
};
#endif