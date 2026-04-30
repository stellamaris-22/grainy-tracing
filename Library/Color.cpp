#include "Color.h"

Color Color::convert_color_255() {
    // Converting colors from [0,1] to [0,255].
    return Color((int)(255.999 * r()),
        	 (int)(255.999 * g()),
    	 	 (int)(255.999 * b()));
}
