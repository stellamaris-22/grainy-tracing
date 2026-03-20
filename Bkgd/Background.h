#include <iostream>
#include <string>
#include <ostream>

class Background {
    public:
    struct Color{
        std::uint16_t r;
        std::uint16_t g;
        std::uint16_t b;
        friend std::ostream &operator<<(std::ostream &os, const Color& c){
            os << c.r <<' '<<c.g<<' '<<c.b<<std::endl;
            return os;
        }
    };
    
    struct Pt{
        std::uint16_t x;
        std::uint16_t y;
        Color color;
    };

        Background();
        ~Background();
        Background(std::uint16_t height, std::uint16_t width);
        void set_height(std::uint16_t h);
        void set_width(std::uint16_t w);
        void set_default_corners();
        void set_top_left_corner(Pt);
        void set_top_right_corner(Pt);
        void set_bottom_left_corner(Pt);
        void set_bottom_right_corner(Pt);
        std::uint16_t get_height();
        std::uint16_t get_width();
        std::string get_mn();
        std::uint16_t get_max_channel_value();
        
        
        private:
            Pt corn_tl, corn_tr, corn_bl, corn_br;
            std::pair<Color, Color> h_sum (const Pt& tgt);
            void v_sum (Pt& tgt, Color m_ab, Color m_cd);
            void paint_one(Pt tgt);
            void paint();
            std::uint16_t max_channel_value{255};
            std::uint16_t height{200};
            std::uint16_t width{400};
            std::string mn{"P3"};
    };