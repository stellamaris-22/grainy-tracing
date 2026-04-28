#include "Color.h"

Color Color::convert_color_255(const Color& pixel_color) {
    // Converting colors from [0,1] to [0,255].
    return Color((int)(255.999 * pixel_color.r()),
        	 (int)(255.999 * pixel_color.g()),
    	 	 (int)(255.999 * pixel_color.b()));
}
