#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome_string(const std::string&);
bool isPalindrome_int(int);

int main()
{
    int number;
    std::cout<<"Enter number:";
    std::cin>>number;
    if(isPalindrome_int(number))
        std::cout<<"The number is palindrome:"<<std::endl;
    else
        std::cout<<"The number is not palindrome:"<<std::endl;

        std::string string;
        std::cout<<"Enter a string :";
        std::cin>>string;
        if(isPalindrome_string(string))
            std::cout<<"The string is plaindrome:"<<std::endl;
        else
            std::cout<<"The string is not palindrome:"<<std::endl;
}

bool isPalindrome_int(int number)
{
    int revers = 0;
    int a, digit;
    a = number;
    bool result = true;

    do
        {
            digit = number%10;
            revers = (revers*10) + digit;
            number = number/10;
        }
    while(number != 0);

        if(a == revers)
            return true;
                return false;
}

bool isPalindrome_string(const std::string& string) 
{
    std::string revers = string;

    std::reverse(revers.begin(),revers.end());

    if(string == revers)
        return true;
            return false;
}