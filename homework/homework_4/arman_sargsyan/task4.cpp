#include <iostream>
#include <vector>
#include "string.h"

bool isPalindrome(const std::string&);
bool isPalindrome(int);


int main(int argc, char const *argv[])
{
    int number;
    std::string text;
    std::cout << "Enter integer for checking: " << std::endl;
    std::cin >> number ;
    std::cout << "Enter string for checking: " << std::endl;
    std::cin >> text;
    std::cout << ( isPalindrome(number) ? "Number is polindrom" : "Number is not polindrome" ) << std::endl;
    std::cout << ( isPalindrome(text) ? "Text is polindrom" : "Text is not polindrome" ) << std::endl;
    return 0;
}

bool isPalindrome(int number){
    std::string number_elems = std::to_string(number);
    return isPalindrome(number_elems);
}

bool isPalindrome(const std::string& number_elems){
    for (int i = 0; i <= number_elems.length() / 2; ++i) {
        if ( number_elems[i] != number_elems[number_elems.length() - 1 - i] ) {
            return false;
        }
    }
    return true;
}

