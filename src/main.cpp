#include <iostream>

#include "mathematics/complex.hpp"

#include "lua/LuaScript.h"

#include "utils/FileSystem.hpp"

/// Main program function
int main(int argc, char **argv)
{
    auto path = utils::filesystem::get_current_path();
    std::cout << "Current main path: " << path << std::endl;

    utils::filesystem::print_directory_entries(path);

    Complex complex(4,5);

    std::cout << "complex.getImag() = " << complex.getImag() << std::endl;
    std::cout << "complex.getReal() = " << complex.getReal() << std::endl;
    std::cout << "complex.abs() = " << complex.abs() << std::endl;

    LuaScript script("assets/scripts/Player.lua");
    float posX = script.get<float>("player.position.x");
    float posY = script.get<float>("player.position.y");
    std::string filename = script.get<std::string>("player.filename");
    int hp = script.get<int>("player.HP");

    std::cout<<"Position X = "<<posX<<", Y = "<<posY<<std::endl;
    std::cout<<"Filename:"<<filename<<std::endl;
    std::cout<<"HP:"<<hp<<std::endl;

    std::vector<std::string> acquired_paths;
    utils::filesystem::get_tree(path, acquired_paths);

    std::cout << "Setup status: SUCCESS !" << std::endl;
    // std::cin.get();

    return 0;
}
