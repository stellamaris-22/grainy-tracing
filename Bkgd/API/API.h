#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include "../Camera/Camera.h"
// #include "../Background/Background.h"

class API{
    public:
        void render();
        API(std::string file_name);
        private:
        Camera camera;
        Background bkgd;
        std::string in_file_name;
        std::string out_file_name;
        
        void init_engine(); //add running options parameter (?)
        void run();
        void parse();
        void clean_up();
        void background();
        
        struct Line{
            std::string tag_name;
            std::vector<std::pair<std::string,std::string>> params;
        };







};