#include <iostream>
#include <string>
#include <ostream>
#include "Film.h"


void Film::set_type(std::string type){
    this->type = type;
}
void Film::set_x_res(std::uint16_t x_res){
    this->x_res = x_res;
}
void Film::set_y_res(std::uint16_t y_res){
    this->y_res = y_res;
}
void Film::set_out_file_name(std::string out_file_name){
    this->out_file_name = out_file_name;
}
void Film::set_img_type(std::string img_type){
    this->img_type = img_type;
}

std::string Film::get_type(){
    return type;
}
std::uint16_t Film::get_x_res(){
    return x_res;
}
std::uint16_t Film::get_y_res(){
    return y_res;
}
std::string Film::get_out_file_name(){
    return out_file_name;
}
std::string Film::get_img_type(){
    return img_type;
}

void Film::write_image(){
    
}