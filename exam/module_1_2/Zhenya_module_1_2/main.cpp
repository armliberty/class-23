#include "prefix.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2 || !av[1])
            throw std::runtime_error("Error: ac should be 2, give infix expression as a second argument");
        std::string str(av[1]);
        std::cout << "The resulting prefix of given infix is: " << convertInfixToPrefix(str) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}