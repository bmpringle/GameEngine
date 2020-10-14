#include"Tile.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Tile::Tile(float _x, float _y) {
    x = _x;
    y = _y;
    initVAO();
}

void Tile::render(int program, float unitsToNormal) {

    float vertices[] = {
        0, 0, 0,
        1, 0, 0,
        1, 1, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0
    };

    float colors[] = {
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 1, 1            
    };

    float uv[] = {
        0, 0,
        1, 0,
        1, 1,
        0, 0,
        0, 1,
        1, 1
    };

    for(int i = 0; i<18; i+=3) {
        vertices[i] = vertices[i]+x;
        vertices[i+1] = vertices[i+1]+y;
    }

    for(int i = 0; i<18; ++i) {
        vertices[i] = vertices[i]*unitsToNormal;
    }

    if(hasTexture) glBindTexture(GL_TEXTURE_2D, TBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBOV);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBOC);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_DYNAMIC_DRAW);

    if(hasTexture) {
        glBindBuffer(GL_ARRAY_BUFFER, VBOT);
        glBufferData(GL_ARRAY_BUFFER, sizeof(uv), uv, GL_DYNAMIC_DRAW);
    }

    glUseProgram(program);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Tile::initVAO() {
    std::vector<unsigned int> VAOarray = allocateVAO();
    VAO = VAOarray[0];
    VBOV = VAOarray[1];
    VBOC = VAOarray[2];
    VBOT = VAOarray[3];
}

//should be formatted as GL_RGB
void Tile::loadTexture(std::string asset) {   

    int width, height, nrChannels;
    unsigned char *data = stbi_load(("src/assets/"+asset).c_str(), &width, &height, &nrChannels, 0); 

    if(data  == nullptr) abort();

    glBindVertexArray(VAO);

    glGenTextures(1, &TBO);

    glBindTexture(GL_TEXTURE_2D, TBO); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);

    glBindVertexArray(0);

    hasTexture = true;
}

void Tile::unloadTexture() {
    glDeleteTextures(1, &TBO);
    hasTexture = false;
}