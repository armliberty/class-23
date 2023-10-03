#include <iostream>
#include <cmath>

int input(std::string msg);
bool isPrime(int);

int main()
{
    int x = input("Insert a positive number");
    if (x == 1 || x == 0)
    {
        std::cout << "Inserted number is neither prime nor composite." << std::endl;
        return 0;
    }

    if (isPrime(x))
        std::cout << "Inserted number is prime." << std::endl;
    else
        std::cout << "Inserted number is composite." << std::endl;

    return 0;
}

int input(std::string msg)
{
    if (!msg.empty())
    {
        std::cout << msg << ": ";
    }
    double value;
    do
    {
        std::cin >> value;
        if (value < 0)
            std::cout << "Please insert a positive number: ";
    } while (value < 0);

    return value;
}

bool isPrime(int x)
{
    bool t = true;
    for (int i = 2; i < x / 2; i++)
        if (x % i == 0)
        {
            t = false;
            return t;
        }

    return t;
}