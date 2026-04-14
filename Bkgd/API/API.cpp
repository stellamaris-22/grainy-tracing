#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "API.h"

Background::Color normalized_to_normal(float r, float g, float b){
    Background::Color c;
    c.r = 255*r;
    c.g = 255*g;
    c.b = 255*b;
    return c;
}

std::vector<std::string> tokenizer(std::string line, char tk=' '){
    std::vector<std::string> tokens;
    std::string curr_token;

    for (auto c : line){
        if(c == tk){
            tokens.push_back(curr_token);
            curr_token = "";
        } else {
            curr_token += c;
        }
    }
    tokens.push_back(curr_token);
    return tokens;
}

API::API(std::string file_name){
    this->in_file_name = file_name;
}

void API::render(){
    parse();
    // std::cout<<"PARSED, IMMA PAINT \n"<<out_file_name<<std::endl;
    bkgd.paint(out_file_name);
}

































std::pair<std::string,std::string> rmv_tag (std::string str){
    std::string tag;
    std::string no_tag;
    bool flag{false};
    for(auto c : str){
        // std::cout<<"\nCHAR: "<<c<<'!';
        if(c == ' ') flag = true;
        if(flag) no_tag += c;
        else tag +=c;
    }
    // std::cout<<std::endl;
    return {tag, no_tag};
}

std::string rmv_tokens(std::string str){
    std::string treated;
    for(auto c : str){
        switch (c){
            case '<':continue;
            case '=':continue;
            case '/':continue;
            case '>':continue;
            default: treated +=c;
        }

    }
    return treated;
}

void API::parse(){
    // std::cout<< "PARSING\n";
    std::ifstream file(in_file_name);
    std::string line;


    while(getline(file >> std::ws, line)) {
        // std::cout<<line<<std::endl;
        // std::cout<<"vs.\n";
        std::pair<std::string,std::string> untagged{rmv_tag(line)};
        // std::cout<<"TAG: "<<untagged.first<<"\nREST: "<<untagged.second<<std::endl;
        line = rmv_tokens(untagged.second);
        std::vector<std::string> broken = tokenizer(line, '"');
        for(auto s :broken){
            // std::cout<<s<<std::endl;
        }

        
        
            if(untagged.first == "<RT3>") continue;
            if(untagged.first == "<camera"){ //camera
                // std::cout<<"FOUND CAMERA\n";
                //ignore for now
                continue;
            }
            else if(untagged.first == "<object"){ //object
                // std::cout<<"FOUND OBJECT\n";
                //ignore for now
                continue;
            }
            else if(untagged.first == "<light"){ //light
                // std::cout<<"FOUND LIGHT\n";
                //ignore for now
                continue;
            }
            else if(untagged.first == "<material"){ //material
                // std::cout<<"FOUND MATERIAL\n";
                //ignore for now
                continue;
            }
            else if(untagged.first == "<film"){ //film
                // std::cout<<"FOUND FILM\n";
                for(auto i{0}; i<broken.size()-1; i+=2){
                    // std::cout<<broken[i]<<' '<<broken[i+1]<<std::endl;
                    if(broken[i] == " type"){
                        camera.film.set_type(broken[i+1]);
                    }
                    else if(broken[i] == " x_res"){
                        camera.film.set_x_res(std::stoi(broken[i+1]));
                        bkgd.set_width(std::stoi(broken[i+1]));
                    }
                    else if(broken[i] == " y_res"){
                        camera.film.set_y_res(std::stoi(broken[i+1]));
                        bkgd.set_height(std::stoi(broken[i+1]));
                    }
                    else if(broken[i] == " filename"){
                        // std::cout<<"GOT FILENAME!! "<<broken[i+1]<<"!!!\n";
                        camera.film.set_out_file_name(broken[i+1]);
                        out_file_name = broken[i+1];
                    }
                    else if(broken[i] == " img_type"){
                        camera.film.set_img_type(broken[i+1]);
                    }
                }        
            }
            else if(untagged.first == "<background"){ //background
                // std::cout<<"FOUND BKGD\n";
                for(auto i{0}; i<broken.size()-1; i+=2){
                    // std::cout<<broken[i]<<'='<<broken[i+1]<<std::endl;
                    if(broken[i] == " type"){
                        // img
                    }
                    else if(broken[i] == " color"){//one color only
                        std::vector<std::string> rgb{tokenizer(broken[i+1])};
                        if(rgb[0][1] == '.' || rgb[1][1] == '.' || rgb[2][1] == '.'){
                            bkgd.corn_bl.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                            bkgd.corn_br.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                            bkgd.corn_tl.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                            bkgd.corn_tr.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                        } else {
                            bkgd.corn_bl.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
    static_cast<uint16_t>(std::stoi(rgb[1])),
    static_cast<uint16_t>(std::stoi(rgb[2]))
};
                            bkgd.corn_br.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
    static_cast<uint16_t>(std::stoi(rgb[1])),
    static_cast<uint16_t>(std::stoi(rgb[2]))
};
                            bkgd.corn_tl.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
    static_cast<uint16_t>(std::stoi(rgb[1])),
    static_cast<uint16_t>(std::stoi(rgb[2]))
};
                            bkgd.corn_tr.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
    static_cast<uint16_t>(std::stoi(rgb[1])),
    static_cast<uint16_t>(std::stoi(rgb[2]))
};
                        }
                    }
                    else if(broken[i] == " bl"){
                        std::vector<std::string> rgb{tokenizer(broken[i+1])};
                        if(rgb[0][1] == '.' || rgb[1][1] == '.' || rgb[2][1] == '.'){
                            bkgd.corn_bl.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                        }
                        else {
                            bkgd.corn_bl.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
                                static_cast<uint16_t>(std::stoi(rgb[1])),
                                static_cast<uint16_t>(std::stoi(rgb[2]))
                            };
                        }
                    }
                    else if(broken[i] == " br"){
                        std::vector<std::string> rgb{tokenizer(broken[i+1])};
                        if(rgb[0][1] == '.' || rgb[1][1] == '.' || rgb[2][1] == '.'){
                            bkgd.corn_br.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                        }
                        else {
                            bkgd.corn_br.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
    static_cast<uint16_t>(std::stoi(rgb[1])),
    static_cast<uint16_t>(std::stoi(rgb[2]))
};
                        }
                    }
                    else if(broken[i] == " tl"){
                        std::vector<std::string> rgb{tokenizer(broken[i+1])};
                        if(rgb[0][1] == '.' || rgb[1][1] == '.' || rgb[2][1] == '.'){
                            bkgd.corn_tl.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                        }
                        else {
                            bkgd.corn_tl.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
    static_cast<uint16_t>(std::stoi(rgb[1])),
    static_cast<uint16_t>(std::stoi(rgb[2]))
};
                        }
                    }
                    else if(broken[i] == " tr"){
                        std::vector<std::string> rgb{tokenizer(broken[i+1])};
                        if(rgb[0][1] == '.' || rgb[1][1] == '.' || rgb[2][1] == '.'){
                            bkgd.corn_tr.color = normalized_to_normal(std::stof(rgb[0]),std::stof(rgb[1]),std::stof(rgb[2]));
                        }
                        else {
                            bkgd.corn_tr.color = {static_cast<uint16_t>(std::stoi(rgb[0])),
    static_cast<uint16_t>(std::stoi(rgb[1])),
    static_cast<uint16_t>(std::stoi(rgb[2]))
};
                        }
                    }
                } 
            }


        if(untagged.first == "<RT3/>") continue;
        
    }
}
