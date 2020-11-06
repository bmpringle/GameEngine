#include"HUD.h"

HUD::HUD(float _unitToNormal, World* world) : unitToNormal(_unitToNormal) {
    emptyhealthbar.loadTexture("emptyhealthbar.png");
    healthbar.loadTexture("healthbar.png");
    
    emptyhealthbar.world = world;
    healthbar.world = world;
}

void HUD::render(int program, int texprogram) {
    if(emptyhealthbar.hasTexture) {
        emptyhealthbar.render(texprogram, unitToNormal);
    }else {
        emptyhealthbar.render(program, unitToNormal);
    }
    if(healthbar.hasTexture) {
        healthbar.render(texprogram, unitToNormal);
    }else {
        healthbar.render(program, unitToNormal);
    }
}

void HUD::update(Entity player) {
    std::vector<float> healthbaruv = {
        0, 0,
        player.getHealth()/player.getMaxHealth(), 0,
        player.getHealth()/player.getMaxHealth(), 1,
        0, 0,
        0, 1,
        player.getHealth()/player.getMaxHealth(), 1  
    };

    std::vector<float> oldhealthbarvertices = healthbar.getVertices();

    std::vector<float> healthbarvertices = {
        oldhealthbarvertices[0], oldhealthbarvertices[1], oldhealthbarvertices[2], 
        -1/unitToNormal+(player.getHealth()/player.getMaxHealth())*static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)+1/unitToNormal), oldhealthbarvertices[4], oldhealthbarvertices[5], 
        -1/unitToNormal+(player.getHealth()/player.getMaxHealth())*static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)+1/unitToNormal), oldhealthbarvertices[7], oldhealthbarvertices[8],
        oldhealthbarvertices[9], oldhealthbarvertices[10], oldhealthbarvertices[11],
        oldhealthbarvertices[12], oldhealthbarvertices[13], oldhealthbarvertices[14],
        -1/unitToNormal+(player.getHealth()/player.getMaxHealth())*static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)+1/unitToNormal), oldhealthbarvertices[16], oldhealthbarvertices[17]
    };

    healthbar.setUV(healthbaruv);
    healthbar.setVertices(healthbarvertices);
}