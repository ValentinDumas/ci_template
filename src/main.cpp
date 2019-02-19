#include <hello.h>
#include <iostream>

/// Main program function
int main(int argc, char **argv)
{
    std::cout << "Setup status: SUCCESS" << std::endl;
    // std::cin.get();

    int r = add(1,3);
    std::cout << "R = " << r << std::endl;

    return 0;
}
