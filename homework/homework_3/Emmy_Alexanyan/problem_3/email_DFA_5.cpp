#include<iostream>
#include<string>


bool Validated(std::string emailAddres);
bool isLetter(char element);
bool isDigit(char element);




int main()
{
    std::string email;
    std::cout << "Input email addres: ";
    std::getline(std::cin, email);

    if (Validated(email))
    {
        std::cout << "Email addres is valid " << std::endl;
    }
    else
    {
        std::cout << "Email addres is not valid" << std::endl;
    }
}


bool Validated(std::string email)
{
    int current_state = 0;
    for (int i = 0; i < email.size(); ++i)
    {
        if (current_state == 0 && (isDigit(email[i]) || isLetter(email[i])))
        {
            current_state = 4;
        }
        else if (current_state == 0 && (email[i] == '.' || email[i] == '-' || email[i] == '@'))
        {
            current_state = 5;
        }
        else if (current_state == 4 && email[i] == '@')
        {
            current_state = 3;
        }
        else if (current_state == 4 && (isDigit(email[i]) || isLetter(email[i]) || email[i] == '.' || email[i] == '-'))
        {
            current_state = 4;
        }
        else if (current_state == 3 && (isLetter(email[i]) || isDigit(email[i])))
        {
            current_state = 2;
        }
        else if (current_state == 3 && (email[i] == '@' || email[i] == '-' || email[i] == '.'))
        {
            current_state = 5;
        }
        else if (current_state == 2 && email[i] == '.')
        {
            current_state = 1;
        }
        else if (current_state == 2 && (isLetter(email[i]) || isDigit(email[i]) || email[i] == '-'))
        {
            current_state = 2;
        }
        else if (current_state == 2 && email[i] == '@')
        {
            current_state = 5;
        }
        else if (current_state == 1 && (isDigit(email[i]) || email[i] == '.' || email[i] == '-' || email[i] == '@'))
        {
            current_state = 5;
        }
        else if (current_state == 1 && isLetter(email[i]))
        {
            current_state = 1;
        }
        else
        {
            current_state = 5;
        }
    }

    return current_state == 1;
}

bool isLetter(char c)
{
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57);
}

bool isDigit(char c)
{
    return (c >= 48) && (c <= 57);
}
