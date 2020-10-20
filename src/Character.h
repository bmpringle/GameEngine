#include"Tile.h"

class Character : public Tile {
    public:
        std::string characterAtlas;
        unsigned char* data;
        int width, height, nrChannels;

        Character(std::vector<float> uvIn, std::string typeName);

        Character(std::vector<float> uvIn, std::string typeName, std::vector<float> _vertices);

        void loadTexture();
};