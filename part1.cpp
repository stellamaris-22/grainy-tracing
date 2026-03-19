#include <iostream>
#include <string>

//constants
const std::uint16_t max_channel_value{255};
const std::uint16_t height{200};
const std::uint16_t width{400};
const std::string mn{"P3"};

int main(){
    std::uint16_t red_value, green_value, blue_value{(std::uint16_t)(0.2*max_channel_value)};
    std::cout<<mn<<std::endl<<width<<' '<<height<<std::endl<<max_channel_value<<std::endl;

    for(std::uint16_t row{0}; row <= height; ++row){
        green_value = (1.0 - (((float)row)/height)) * max_channel_value;
        for(std::uint16_t col{0}; col < width; ++col){
            red_value = (((float)col)/(width - 1)) * max_channel_value;
            std::cout<<red_value<<' '<<green_value<<' '<<blue_value<<std::endl;
        }
    }
}