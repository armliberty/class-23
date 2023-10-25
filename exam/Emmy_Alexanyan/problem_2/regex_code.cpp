#include<iostream>
#include<string>


bool Validated(std::string text);
bool isLetter(char element);
bool isDigit(char element);




int main()
{
    std::string text;
    std::cout << "Input text: ";
    std::getline(std::cin, text);

    if (Validated(text))
    {
        std::cout << "Input text is valid " << std::endl;
    }
    else
    {
        std::cout << "Input text is not valid" << std::endl;
    }
}


bool Validated(std::string text)
{
    int current_state = 0;
    for (int i = 0; i < text.size(); ++i)
    {
        if (current_state == 0 && text[i] == 97)
        {
            current_state = 4;
            
        }
        else if (current_state == 0 && (isDigit(text[i]) || isLetter(text[i])))
        {
            current_state = 5;
           
        }
        else if (current_state == 4 && (isDigit(text[i]) || isLetter(text[i])))
        {
            current_state = 3;
            
        }
  
        else if (current_state == 3 && text[i] == 98)
        {
            current_state = 1;
         
        }
         else if (current_state == 3 && isLetter(text[i]))
        {
            current_state = 3;
            
        }
    
        else if (current_state == 1 && isLetter(text[i]))
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
    return (c >= 65 && c <= 90) || (c >= 98 && c <= 122) || (c >= 48 && c <= 57);
}

bool isDigit(char c)
{
    return (c >= 48) && (c <= 57);
}
