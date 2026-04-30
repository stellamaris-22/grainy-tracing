#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"

class Color : public Vec3 {
public :
    Color() : Vec3() {};
    Color(float r, float g, float b) : Vec3(r, g, b) {};
    ~Color() = default;

    float r() const {return x();}
    float g() const {return y();}
    float b() const {return z();}

    Color convert_color_255();

};

#endif
