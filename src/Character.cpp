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

    if(typeName != "I" && typeName != "J") {
        for(int i=0; i<vertices.size(); i+=3) {
            vertices[i] = vertices[i]*size;
            vertices[i+1] = vertices[i+1]*size;
            vertices[i+2] = vertices[i+2];
        }   
    }

    if(typeName == "I" || typeName == "J") {
        for(int i=0; i<vertices.size(); i+=3) {
            vertices[i] = vertices[i]*size*((typeName == "I") ? 1.0/4.0 : 1.0/2.0);
            vertices[i+1] = vertices[i+1]*size;
            vertices[i+2] = vertices[i+2];
        }         
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

    if(typeName != "I" && typeName != "J") {
        for(int i=0; i<vertices.size(); i+=3) {
            vertices[i] = vertices[i]*size;
            vertices[i+1] = vertices[i+1]*size;
            vertices[i+2] = vertices[i+2];
        }   
    }

    if(typeName == "I" || typeName == "J") {
        for(int i=0; i<vertices.size(); i+=3) {
            vertices[i] = vertices[i]*size*((typeName == "I") ? 1.0/3.0 : 1.0/2.0);
            vertices[i+1] = vertices[i+1]*size;
            vertices[i+2] = vertices[i+2];
        }         
    }
}

void Character::loadTexture() {
    Tile::loadTexture(data, width, height, nrChannels);
}