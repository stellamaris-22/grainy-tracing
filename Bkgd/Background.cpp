#include <iostream>
#include "Background.h"

Background::~Background() = default;
Background::Background(std::uint16_t height, std::uint16_t width){
    this->height = height; 
    this->width = width;
    set_default_corners();
    paint();
}
void Background::set_height(std::uint16_t height){
    this->height = height;
    set_default_corners();
    paint(); 
}
void Background::set_width(std::uint16_t width){
    this->width = width;
    set_default_corners();
    paint();
}

void Background::set_top_left_corner(Background::Pt tlc){
    corn_tl = tlc;
}
void Background::set_top_right_corner(Background::Pt trc){
    corn_tr = trc;    
}
void Background::set_bottom_left_corner(Background::Pt blc){
    corn_bl = blc;    
}
void Background::set_bottom_right_corner(Background::Pt brc){
    corn_br = brc;    
}

std::uint16_t Background::get_height(){
    return height;
}
std::uint16_t Background::get_width(){
    return width;
}
std::string Background::get_mn(){
    return mn;
}

std::uint16_t Background::get_max_channel_value(){
    return max_channel_value;
}





Background::Background(){
    set_default_corners();
    paint();
}

void Background::set_default_corners(){
    Pt corners;
    //first, bottom left
    corners.x = 0;
    corners.y = height-1;
    corners.color.r = 0;
    corners.color.g = 0;
    corners.color.b = 0;
    set_bottom_left_corner(corners);

    //second, bottom right
    corners.x = width-1;
    corners.y = height-1;
    corners.color.r = 0;
    corners.color.g = 0;
    corners.color.b = 0;
    set_bottom_right_corner(corners);

    //third, top left
    corners.x = 0;
    corners.y = 0;
    corners.color.r = 0;
    corners.color.g = 0;
    corners.color.b = max_channel_value;
    set_top_left_corner(corners);
    
    //last, top right
    corners.x = width-1;
    corners.y = 0;
    corners.color.r = max_channel_value;
    corners.color.g = max_channel_value;
    corners.color.b = max_channel_value;
    set_top_right_corner(corners);
};



std::pair<Background::Color, Background::Color> Background::h_sum (const Pt& tgt){
    Color m_ab, m_cd;
    m_ab.r = (float)(width-tgt.x)/(width - 1)*corn_bl.color.r + (float)(tgt.x)/(width - 1)*corn_br.color.r;
    m_ab.g = (float)(width-tgt.x)/(width - 1)*corn_bl.color.g + (float)(tgt.x)/(width - 1)*corn_br.color.g;
    m_ab.b = (float)(width-tgt.x)/(width - 1)*corn_bl.color.b + (float)(tgt.x)/(width - 1)*corn_br.color.b;

    m_cd.r = (float)(width-tgt.x)/(width - 1)*corn_tl.color.r + (float)(tgt.x)/(width - 1)*corn_tr.color.r;
    m_cd.g = (float)(width-tgt.x)/(width - 1)*corn_tl.color.g + (float)(tgt.x)/(width - 1)*corn_tr.color.g;
    m_cd.b = (float)(width-tgt.x)/(width - 1)*corn_tl.color.b + (float)(tgt.x)/(width - 1)*corn_tr.color.b;
    
    return {m_ab, m_cd};
}

void Background::v_sum (Background::Pt& tgt, Background::Color m_ab, Background::Color m_cd){
    tgt.color.r = (float)(height-tgt.y)/ (height - 1)*m_cd.r + (float)(tgt.y)/ (height - 1)*m_ab.r;
    tgt.color.g = (float)(height-tgt.y)/ (height - 1)*m_cd.g + (float)(tgt.y)/ (height - 1)*m_ab.g;
    tgt.color.b = (float)(height-tgt.y)/ (height - 1)*m_cd.b + (float)(tgt.y)/ (height - 1)*m_ab.b;
}

void Background::paint_one(Pt tgt){
    std::pair<Color,Color> mid_v{h_sum(tgt)};
    v_sum(tgt, mid_v.first, mid_v.second);

    std::cout<<tgt.color.r<<' '<<tgt.color.g<<' '<<tgt.color.b<<std::endl;
};


void Background::paint(){
    std::cout<<mn<<std::endl<<width<<' '<<height<<std::endl<<max_channel_value<<std::endl;
    for(std::uint16_t row{0}; row < height; ++row){
        for(std::uint16_t col{0}; col < width; ++col){
             if(row == corn_bl.y && col == corn_bl.x) std::cout<<corn_bl.color;
            else if(row == corn_br.y && col == corn_br.x) std::cout<<corn_br.color;
            else if(row == corn_tl.y && col == corn_tl.x) std::cout<<corn_tl.color;
            else if(row == corn_tr.y && col == corn_tr.x) std::cout<<corn_tr.color;
            else paint_one({col, row});
        }
    }
};