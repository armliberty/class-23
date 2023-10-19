#include<iostream>
#include<vector>
#include<string>

std::string input(std::string msg);
bool isValid(std::string emailAddres);
bool isLetter(char element);
bool isSymbol(char element);
bool isDigit(char element);

int main()
{
    auto email = input("Input email addres");
    auto validation = isValid(email);
    if (validation)
    {
        std::cout << "Email addres is valid " << std::endl;
    }
    else
    {
        std::cout << "Email addres is not valid" << std::endl;
    }
}

std::string input(std::string msg)
{
    if (!msg.empty())
    {
        std::cout << msg << ":" << std::endl;
    }
    std::string email;
    std::getline(std::cin, email);
    return email;
}

bool isValid(std::string email)
{
    char c;

    int atsignIndex = 0;
    for (int i = 0; i < email.size(); ++i)
    {
        if (email[i] == '@')
        {
            atsignIndex = i;
        }
    }
    if (atsignIndex == 0) {
        return false;
    }

    int index = 0;
    while (index < atsignIndex)
    {
        //before @
        c = email[index];
        if (index == 0 || index == atsignIndex - 1) {
            if (!isLetter(c))
            {
                return false;
            }
        }
        else if (!(isLetter(c) || isDigit(c) || isSymbol(c)))
        {
            return false;
        }

        ++index;
    }

    int pointIndex = 0;
    for (int i = atsignIndex; i < email.size(); ++i)
    {
        if (email[i] == '.')
        {
            pointIndex = i;
        }
    }

    if (pointIndex == 0) {
        return false;
    }

    index = atsignIndex + 1;
    while (index < pointIndex)
    {
        //before .
        c = email[index];
        if (index == atsignIndex + 1 || index == pointIndex - 1)
        {
            if (!isLetter(c))
            {
                return false;
            }
        }
        else
        {
            if (!(isLetter(c) ||  isDigit(c) || isSymbol(c)))
            {
                return false;
            }
        }

        ++index;
    }

    for (index = pointIndex + 1; index < email.size(); ++index)
    {
        if (!isLetter(email[index]))
        {
            return false;
        }
    }

    return true;
}

bool isLetter(char c)
{
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

bool isSymbol(char c)
{
    return 45 == c || 46 == c || 95 == c;
}

bool isDigit(char c)
{
    return (c >= 48) && (c <= 57);
}
