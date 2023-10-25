#include<iostream>
#include<vector>
#include<string>

std::string input(std::string msg);
bool isValid(std::string regex);

int main()
{
    auto regex = input("Regex");
    auto validation = isValid(regex);
    if (validation)
    {
        std::cout << "Regex is valid " << std::endl;
    }
    else
    {
        std::cout << "Regex is not valid" << std::endl;
    }
}

std::string input(std::string msg)
{
    if (!msg.empty())
    {
        std::cout << msg << ":" << std::endl;
    }
    std::string regex;
    std::getline(std::cin, regex);
    return regex;
}

bool isValid(std::string regex)
{
    int check = 0;
    for (int i = 0; i < regex.size(); ++i) {
        if (regex[i] == 'a') {
            check++;
            break;
        
        }
    }
    if (check == 0) {
        return regex[regex.size() - 1] == 'b';
    }
    else return false;
    }
           