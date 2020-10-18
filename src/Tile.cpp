#include"Tile.h"
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include"World.h"

Tile::Tile(float _x, float _y) {
    x = _x;
    y = _y;
    z = 0;
    initVAO();
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);

    float iverts[] = {
        0, 0, 0,
        1, 0, 0,
        1, 1, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0
    };

    for(int i=0; i<18; ++i) {
        vertices.push_back(iverts[i]);
    }
}

Tile::Tile(float _x, float _y, std::vector<float> _vertices) {
    x = _x;
    y = _y;
    z = 0;
    initVAO();
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);

    vertices = _vertices;
}

Tile::Tile(float _x, float _y, std::string _type, std::vector<float> _vertices) {
    x = _x;
    y = _y;
    z = 0;
    initVAO();
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);
    type = _type;

    vertices = _vertices;
}

Tile::Tile(float _x, float _y, std::string _type) {
    x = _x;
    y = _y;
    z = 0;
    initVAO();
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);
    permissable.push_back(true);
    type = _type;

    float iverts[] = {
        0, 0, 0,
        1, 0, 0,
        1, 1, 0,
        0, 0, 0,
        0, 1, 0,
        1, 1, 0
    };

    for(int i=0; i<18; ++i) {
        vertices.push_back(iverts[i]);
    }
}

void Tile::setPermissable(int direction, bool option) {
    permissable[direction] = option;
}

bool Tile::getPermissable(int direction) {
    return permissable[direction];
}

void Tile::render(int program, float unitsToNormal, float _x, float _y) {

    float tempvertices[vertices.size()];

    for(int i=0; i<vertices.size(); ++i) {
        tempvertices[i] = vertices[i];
    }

    float colors[] = {
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,     
    };

    float uv[] = {
        0, 0,
        1, 0,
        1, 1,
        0, 0,
        0, 1,
        1, 1
    };

    for(int i = 0; i<vertices.size(); i+=3) {
        tempvertices[i] = tempvertices[i]+x+_x-world->getPlayer()->getX();
        tempvertices[i+1] = tempvertices[i+1]+y+_y-world->getPlayer()->getY();
        tempvertices[i+2] = tempvertices[i+2]+z;
    }

    for(int i = 0; i<vertices.size(); ++i) {
        tempvertices[i] = tempvertices[i]*unitsToNormal;
    }

    if(hasTexture) glBindTexture(GL_TEXTURE_2D, TBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBOV);
    glBufferData(GL_ARRAY_BUFFER, sizeof(tempvertices), tempvertices, GL_DYNAMIC_DRAW);

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

void Tile::render(int program, float unitsToNormal) {
    render(program, unitsToNormal, 0, 0);
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
    unsigned char *data = stbi_load(("/home/bmp/Development/C++/Game/src/assets/"+asset).c_str(), &width, &height, &nrChannels, 0); 
    //stbi_write_png(("src/assets/"+asset).c_str(), width, height, nrChannels, data, width*nrChannels);

    if(data  == nullptr) abort();

    glBindVertexArray(VAO);

    glGenTextures(1, &TBO);

    glBindTexture(GL_TEXTURE_2D, TBO); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    if(nrChannels == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }

    glGenerateMipmap(GL_TEXTURE_2D);

    glBindVertexArray(0);

    hasTexture = true;
}

void Tile::unloadTexture() {
    glDeleteTextures(1, &TBO);
    hasTexture = false;
}

float Tile::getX() {
    return x;
}

float Tile::getY() {
    return y;
}

float Tile::getZ() {
    return z;
}

void Tile::changePos(float xUnits, float yUnits) {
    x+=xUnits;
    y+=yUnits;
}

void Tile::changePos(float xUnits, float yUnits, float zUnits) {
    x+=xUnits;
    y+=yUnits;
    z+=zUnits;
}

void Tile::setPos(float _x, float _y) {
    x = _x;
    y = _y;
}

void Tile::setPos(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

void Tile::setType(std::string _type) {
    type = _type;
}

void Tile::addAttachment(Tile a) {
    a.world = world;
    attachments.push_back(a);
}

std::vector<Tile>* Tile::getAttachments() {
    return &attachments;
}

void Tile::interactionOn(Entity* e) {
    interactionFunction(world, e);
}

void Tile::renderAttachments(int program, float unitsToNormal, int _x, int _y) {
    for(Tile a : attachments) {
        a.render(program, unitsToNormal, x+_x, y+_y);
    }

    for(Tile a : attachments) {
        a.renderAttachments(program, unitsToNormal, _x+x, _y+y);
    }
}