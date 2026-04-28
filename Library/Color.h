#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"

class Color : public Vec3 {
public :
    float r(){return vector[0];}
    float g(){return vector[1];}
    float b(){return vector[2];}

    void convert_color_255(const Color& pixel_color);

};

#endif
