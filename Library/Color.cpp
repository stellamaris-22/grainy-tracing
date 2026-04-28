#include "Color.h"

void Color::convert_color_255(const Color& pixel_color) {
    // Converting colors from [0,1] to [0,255].
    vector[0] = (int)(255.999 * pixel_color.r());
    vector[1] = (int)(255.999 * pixel_color.g());
    vector[2] = (int)(255.999 * pixel_color.b());
}
