#ifndef HUD_H
#define HUD_H

#include"Tile.h"
#include"Entity.h"
class HUD {
    public:
        HUD(float _unitToNormal, World* world);

        void render(int program, int texprogram);

        void update(Entity player);
    private:
        float unitToNormal;
        Tile emptyhealthbar = Tile(0, 0, "emptyhealthbar", {-1/unitToNormal, 1/unitToNormal, -4, static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)), 1/unitToNormal, -4, static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)),  static_cast<float>(1/(unitToNormal)-((float)1/(unitToNormal)*(float)0.2)/2.0), -4, -1/unitToNormal, 1/unitToNormal, -4, -1/unitToNormal,  static_cast<float>(1/(unitToNormal)-((float)1/(unitToNormal)*(float)0.2)/2.0), -4, static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)),  static_cast<float>(1/(unitToNormal)-((float)1/(unitToNormal)*(float)0.2)/2.0), -4});
        Tile healthbar = Tile(0, 0, "healthbar", {-1/unitToNormal, 1/unitToNormal, -5, static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)), 1/unitToNormal, -5, static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)),  static_cast<float>(1/(unitToNormal)-((float)1/(unitToNormal)*(float)0.2)/2.0), -5, -1/unitToNormal, 1/unitToNormal, -5, -1/unitToNormal,  static_cast<float>(1/(unitToNormal)-((float)1/(unitToNormal)*(float)0.2)/2.0), -5, static_cast<float>(-1/unitToNormal+((1/unitToNormal)/2.0)),  static_cast<float>(1/(unitToNormal)-((float)1/(unitToNormal)*(float)0.2)/2.0), -5});
};
#endif