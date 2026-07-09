#include <iostream>
#include <string>
#include <ostream>

#include "../Film/Film.h"

class Camera{
    public:
        Film film;

        void set_type(std::string);
        std::string get_type();
    private:
        std::string type;
};