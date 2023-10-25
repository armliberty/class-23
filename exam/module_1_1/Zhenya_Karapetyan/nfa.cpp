#include <iostream>

void input(std::string &str)
{
    std::cout << "Enter string to check: " << std::endl;
    std::getline(std::cin, str);
}

void algo(const std::string &str)
{
    int i;
    int size;

    i = -1;
    size = str.size();
    while (++i < size)
    {
        if (str[i] == 'a' && str[i + 1] && str[i + 1] == 'a' && str[size - 1] != 'b')
        {
            throw std::invalid_argument("The given string is not proper");
        }
    }
}

int main(int argc, char **av)
{
    try
    {
        std::string str;
        input(str);
        algo(str);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << "Exception caught" << e.what() << std::endl;
    }
}
