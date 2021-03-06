#ifndef WORLD_H
#define WORLD_H
#include<vector>
#include"Tile.h"
#include"Entity.h"
#include<chrono>
#include"Character.h"
#include<map>
#include"HUD.h"

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

        void showTextBox(std::string text, bool show);

        bool isShowingTextBox();

        void cycleTextOffset();

    private:
        std::vector<Tile> tiles = std::vector<Tile>();
        std::vector<Entity> entities = std::vector<Entity>();
        float unitToNormal = 1.0/5.0;
        Entity player = Entity(0, 0);

        HUD hud;

        Tile textbox = Tile(0, 0, "textbox", {-1/unitToNormal, -1/unitToNormal, -4, 1/unitToNormal, -1/unitToNormal, -4, 1/unitToNormal, -1/(unitToNormal*2), -4, -1/unitToNormal, -1/unitToNormal, -4, -1/unitToNormal, -1/(unitToNormal*2), -4, 1/unitToNormal, -1/(unitToNormal*2), -4});
        std::string textDisplayed = "";
        float yMin = 0;
        float yMax = 0;
        float textOffset = 0;

        bool showTextbox = false;
        std::vector<Character> characters = std::vector<Character>();
        std::map<char, int> lettersToNumbers = std::map<char, int>();        

        void renderTextBox(int program, int textprogram);
};
#endif