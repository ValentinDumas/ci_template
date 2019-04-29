#include <iostream>

#include "mathematics/complex.hpp"

/// Main program function
int main(int argc, char **argv)
{
    Complex complex(4,5);

    std::cout << "complex.getImag() = " << complex.getImag() << std::endl;
    std::cout << "complex.getReal() = " << complex.getReal() << std::endl;
    std::cout << "complex.abs() = " << complex.abs() << std::endl;

    std::cout << "Setup status: SUCCESS !" << std::endl;
    // std::cin.get();

    return 0;
}
