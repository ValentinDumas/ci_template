#include <iostream>

#include "mathematics/complex.hpp"

#include "lua/LuaScript.h"

#include "utils/types.h"
#include "utils/FileSystem.h"

/// Main program function
int main(int argc, char **argv)
{



    auto path = utils::filesystem::get_current_path();
    std::cout << "Current main path: " << path << std::endl;

    utils::filesystem::list_directory_entries(path);

    auto a = utils::filesystem::get_entry(path + "\\ci_template.exe");



    auto t_index = getTypeIndex<int>();

    Complex complex(4,5);

    std::cout << "complex.getImag() = " << complex.getImag() << std::endl;
    std::cout << "complex.getReal() = " << complex.getReal() << std::endl;
    std::cout << "complex.abs() = " << complex.abs() << std::endl;

    LuaScript script("assets\\scripts\\Player.lua");
    float posX = script.get<float>("player.position.x");
    float posY = script.get<float>("player.position.y");
    std::string filename = script.get<std::string>("player.filename");
    int hp = script.get<int>("player.HP");

    std::cout<<"Position X = "<<posX<<", Y = "<<posY<<std::endl;
    std::cout<<"Filename:"<<filename<<std::endl;
    std::cout<<"HP:"<<hp<<std::endl;

    std::cout << "Setup status: SUCCESS !" << std::endl;
    // std::cin.get();

    return 0;
}
