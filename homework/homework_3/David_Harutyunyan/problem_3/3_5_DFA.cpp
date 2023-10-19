#include <iostream>
#include <string>


bool isSymbol(char c);  //checking if the char is symbol
bool isValidEmail(const std::string email);  //checking email validation
std::string input(std::string msg);  //input string


int main()
 {
    const auto email = input("Input an E-mail:");
    if (isValidEmail(email)) 
        std::cout << "Email is valid" << std::endl;
    else 
        std::cout << "Email is not valid" << std::endl;
    
    return 0;
}



std::string input(std::string msg) 
{
    if (!msg.empty()) 
    {
        std::cout << msg << ": ";
    }
        std::string value;
        std::getline(std::cin, value);
    return value;
}


bool isSymbol(char c) 
{
    if (c == '.' | c == '-' | c == '_')
        return true; 
            return false;
}


bool isValidEmail(const std::string Email) 
{
    const auto stateCount = Email.size();
    int state = 0;
    int index = 0;

    for (int i = 0; i < stateCount; ++i)
     {
        char c = Email[i];
       
        if (i == 0) {
            if (isalpha(c)) 
            {
                state++;
            } 
            else 
            {
                state = -1; 
                    return 0;
            }
        } 

        
        else if (index == 0) 
        {
            if (isalpha(c) | isalnum(c) | isSymbol(c)) 
                state++;
            else if (c == '@') 
            {
                state++;
                    index++;
            } 
            else 
            {
                state = -1; 
                    return 0;
            }
        } 
        
        
        else if (index == 1) 
        {
            if (isalpha(c) | c == '-') 
                state++;
            else if(Email[i] == '.')
            {
                state++;
                    index++; 
            }
            else 
            {
                state = -1; 
                    return 0;
            }
        } 
        
        
        else if (index == 2)
         {
            if (isalpha(c)) 
            {
                state++;
            } 
            else 
            {
                state = -1; 
                    return 0;
            }
        }
    }

    if(index == 2 && state != -1)
        return true; 
            return false;
}