#include <iostream>
#include <string>
#include <ostream>
#include "../Background/Background.h"

class Film{
    public:
        void write_image();
        
        void set_type(std::string);
        void set_x_res(std::uint16_t);
        void set_y_res(std::uint16_t);
        void set_out_file_name(std::string);
        void set_img_type(std::string);

        std::string get_type();
        std::uint16_t get_x_res();
        std::uint16_t get_y_res();
        std::string get_out_file_name();
        std::string get_img_type();

        void add(Background::Pt);
    private:
        std::string type;
        std::uint16_t x_res, y_res;
        std::string out_file_name{"out.ppm"};
        std::string img_type;
};
