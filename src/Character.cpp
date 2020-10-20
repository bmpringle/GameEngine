#include"Character.h"
#include "stb_image.h"

Character::Character(std::vector<float> uvIn, std::string typeName) : Tile(0, 0, typeName){
    characterAtlas = "./src/assets/characters.png";
    data = stbi_load((characterAtlas).c_str(), &width, &height, &nrChannels, 0);
    for(int i=0; i<uvIn.size(); i+=2) {
        uv.push_back(uvIn[i]/1024.0);
        uv.push_back((1024.0-uvIn[i+1])/1024.0);
    }
    loadTexture();
    for(int i=0; i<vertices.size(); i+=3) {
        vertices[i] = vertices[i]/3;
        vertices[i+1] = vertices[i+1]/3;
        vertices[i+2] = vertices[i+2];
    }
}

Character::Character(std::vector<float> uvIn, std::string typeName, std::vector<float> _vertices) : Tile(0, 0, typeName){
    characterAtlas = "./src/assets/characters.png";
    data = stbi_load((characterAtlas).c_str(), &width, &height, &nrChannels, 0);
    for(int i=0; i<uvIn.size(); i+=2) {
        uv.push_back(uvIn[i]/1024.0);
        uv.push_back((1024.0-uvIn[i+1])/1024.0);
    }
    vertices = _vertices;
    loadTexture();
    for(int i=0; i<vertices.size(); i+=3) {
        vertices[i] = vertices[i]/3;
        vertices[i+1] = vertices[i+1]/3;
        vertices[i+2] = vertices[i+2];
    }
}

void Character::loadTexture() {
    Tile::loadTexture(data, width, height, nrChannels);
}