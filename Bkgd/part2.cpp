#include <iostream>
#include <string>
#include <ostream>

//constants

const std::uint16_t max_channel_value{255};
const std::uint16_t height{200};
const std::uint16_t width{400};
const std::string mn{"P3"};

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

Pt a{0,199},b{399,199},c{0,0},d{399,0};

std::pair<Color, Color> h_sum (const Pt& tgt){
    Color m_ab, m_cd;
    m_ab.r = (float)(width-tgt.x)/(width - 1)*a.color.r + (float)(tgt.x)/(width - 1)*b.color.r;
    m_ab.g = (float)(width-tgt.x)/(width - 1)*a.color.g + (float)(tgt.x)/(width - 1)*b.color.g;
    m_ab.b = (float)(width-tgt.x)/(width - 1)*a.color.b + (float)(tgt.x)/(width - 1)*b.color.b;

    m_cd.r = (float)(width-tgt.x)/(width - 1)*c.color.r + (float)(tgt.x)/(width - 1)*d.color.r;
    m_cd.g = (float)(width-tgt.x)/(width - 1)*c.color.g + (float)(tgt.x)/(width - 1)*d.color.g;
    m_cd.b = (float)(width-tgt.x)/(width - 1)*c.color.b + (float)(tgt.x)/(width - 1)*d.color.b;

    return {m_ab, m_cd};
}

void v_sum (Pt& tgt, Color m_ab, Color m_cd){
    tgt.color.r = (float)(height-tgt.y)/ (height - 1)*m_cd.r + (float)(tgt.y)/ (height - 1)*m_ab.r;
    tgt.color.g = (float)(height-tgt.y)/ (height - 1)*m_cd.g + (float)(tgt.y)/ (height - 1)*m_ab.g;
    tgt.color.b = (float)(height-tgt.y)/ (height - 1)*m_cd.b + (float)(tgt.y)/ (height - 1)*m_ab.b;
}


int main(){
    Pt tgt;
    std::cin>>tgt.x>>tgt.y;

    a.color.r = 255;
    a.color.g = 0;
    a.color.b = 0;

    b.color.r = 0;
    b.color.g = 255;
    b.color.b = 0;

    c.color.r = 0;
    c.color.g = 0;
    c.color.b = 255;

    d.color.r = 0;
    d.color.g = 0;
    d.color.b = 0; 
    std::pair<Color,Color> mid_v{h_sum(tgt)};
    v_sum(tgt, mid_v.first, mid_v.second);

    std::uint16_t red_value, green_value, blue_value{(std::uint16_t)(0.2 * max_channel_value)};
    std::cout<<mn<<std::endl<<width<<' '<<height<<std::endl<<max_channel_value<<std::endl;

    for(std::uint16_t row{0}; row < height; ++row){
        for(std::uint16_t col{0}; col < width; ++col){
            if(row == tgt.y && col == tgt.x) std::cout<<tgt.color;
            else if(row == a.y && col == a.x) std::cout<<a.color;
            else if(row == b.y && col == b.x) std::cout<<b.color;
            else if(row == c.y && col == c.x) std::cout<<c.color;
            else if(row == d.y && col == d.x) std::cout<<d.color;
            else std::cout<<255<<' '<<255<<' '<<255<<std::endl;
        }
    }
    return 0;
}