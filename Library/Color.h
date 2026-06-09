#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"

class Color : public Vec3 {
public :
    Color() : Vec3() {};
    Color(double r, double g, double b) : Vec3(r, g, b) {};
    ~Color() = default;

    double r() const {return k();}
    double g() const {return l();}
    double b() const {return m();}

    Color convert_color_255();

};

#endif
