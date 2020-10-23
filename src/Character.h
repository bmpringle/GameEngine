#include"Tile.h"

class Character : public Tile {
    public:
        bool lowerCase;
        float size = (108.0/128.0)/7.0;
        std::string characterAtlas;
        unsigned char* data;
        int width, height, nrChannels;

        Character(std::vector<float> uvIn, std::string typeName, bool lower);

        Character(std::vector<float> uvIn, std::string typeName, std::vector<float> _vertices);

        void loadTexture();
};