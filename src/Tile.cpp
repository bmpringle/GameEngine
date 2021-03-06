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

void Tile::setPermissable(E_DIRECTION direction, bool option) {
    permissable[direction] = option;
}

bool Tile::getPermissable(E_DIRECTION direction) {
    return permissable[direction];
}

void Tile::render(int program, float unitsToNormal, float _x, float _y) {
    float tempvertices[vertices.size()];

    if(uv.size() == 0) {
        uv.push_back(0); uv.push_back(0); uv.push_back(1); uv.push_back(0); uv.push_back(1); uv.push_back(1); uv.push_back(0); uv.push_back(0); uv.push_back(0); uv.push_back(1); uv.push_back(1); uv.push_back(1);
    }

    float tempuv[uv.size()];

    for(int i=0; i<vertices.size(); ++i) {
        tempvertices[i] = vertices[i];
    }

    for(int i=0; i<uv.size(); ++i) {
        tempuv[i] = uv[i];
    }


    float colors[] = {
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,
        rBase, gBase, bBase, 1,     
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
        glBufferData(GL_ARRAY_BUFFER, sizeof(tempuv), tempuv, GL_DYNAMIC_DRAW);
    }

    glUseProgram(program);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size()/3);
    glBindVertexArray(0);
}

void Tile::render(int program, float unitsToNormal) {
    render(program, unitsToNormal, 0, 0);
    if(showInterAttachTimed) {
        attachementToShowOnInteractionTimed[0].render(program, unitsToNormal, x, y);
    }

    if(showInterAttach) {
        attachementToShowAndHideOnInteraction[0].render(program, unitsToNormal, x, y);
    }
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

//should be formatted as GL_RGB
void Tile::loadTexture(unsigned char* data, int width, int height, int nrChannels) {   

    if(data  == nullptr) abort();

    glBindVertexArray(VAO);

    glGenTextures(1, &TBO);

    glBindTexture(GL_TEXTURE_2D, TBO); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    if(GLEW_EXT_texture_filter_anisotropic) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, GL_MAX_TEXTURE_MAX_ANISOTROPY);
    }
    
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
    if(attachementToShowOnInteractionTimed.size() > 0) {
        showInterAttachTimed = true;
        start_interaction_show_timer = std::chrono::system_clock::now();
    }

    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now()-start_buffer_show_timer;
    if(attachementToShowAndHideOnInteraction.size() > 0 && elapsed_seconds.count() > 0.5) {
        showInterAttach = !showInterAttach;
        start_buffer_show_timer = std::chrono::system_clock::now();
    }

    elapsed_seconds = std::chrono::system_clock::now()-start_interaction_textbox_close_timer;
    if(hasTextBoxInteractionBehavior && elapsed_seconds.count() > 0.5) {
        world->showTextBox(interactionText, !world->isShowingTextBox());
        start_interaction_textbox_close_timer = std::chrono::system_clock::now();
    }
}

void Tile::renderAttachments(int program, float unitsToNormal, int _x, int _y) {
    for(Tile a : attachments) {
        a.render(program, unitsToNormal, x+_x, y+_y);
        if(a.showInterAttachTimed) {
            a.attachementToShowOnInteractionTimed[0].render(program, unitsToNormal, x+_x, y+_y);
        }

        if(a.showInterAttach) {
            a.attachementToShowAndHideOnInteraction[0].render(program, unitsToNormal, x+_x, y+_y);
        }
    }

    for(Tile a : attachments) {
        a.renderAttachments(program, unitsToNormal, x+_x, y+_y);
    }
}

void Tile::update() {
    if(showInterAttachTimed) {
        std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now()-start_interaction_show_timer;
        if(elapsed_seconds.count() >= timeToShow) {
            showInterAttachTimed = false;
        }
    }
}

void Tile::showAndHideAttachmentOnInteraction(Tile a) {
    a.world = world;
    if(attachementToShowAndHideOnInteraction.size() == 0) {
        attachementToShowAndHideOnInteraction.push_back(a);
    }else {
        attachementToShowAndHideOnInteraction[0] = a;
    }
}

void Tile::showAttachmentOnInteractionTimed(Tile a, float time) {
    a.world = world;
    if(attachementToShowOnInteractionTimed.size() == 0) {
        attachementToShowOnInteractionTimed.push_back(a);
    }else {
        attachementToShowOnInteractionTimed[0] = a;
    }
    timeToShow = time;
}

void Tile::showAndHideTextBoxOnInteraction(std::string text) {
    hasTextBoxInteractionBehavior = true;
    interactionText = text;
}

void Tile::setUV(std::vector<float> uvIn) {
    uv = uvIn;
}

void Tile::setVertices(std::vector<float> vertices) {
    this->vertices = vertices;
}

std::vector<float> Tile::getVertices() {
    return vertices;
}