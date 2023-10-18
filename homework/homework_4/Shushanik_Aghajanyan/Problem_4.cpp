#include <iostream>
#include <string>
#include <algorithm>
bool isPalindrome(const std::string &);
bool isPalindrome(int);
int main(){
    int argument_int;
    std::string argument_string;
    std::cout << "Input integer line: ";
    std::cin >> argument_int;
    std::cout << "Input string: ";
    std::cin >> argument_string;
    if (isPalindrome(argument_string)) {
        std::cout << "String is palindrome" << std::endl;
    }
    else {
        std::cout << "String is not palindrome" << std::endl;
    }
    if (isPalindrome(argument_int)) {
        std::cout << "Integer is palindrome" << std::endl;
    }
    else {
        std::cout << "Integer is not palindrome" << std::endl;
    }
}

bool isPalindrome(const std::string &argument_string) {
    std::string rev_string(argument_string);
    std::reverse(rev_string.begin(), rev_string.end());
    if (argument_string == rev_string) {
        return 1;
    }
    else { 
        return 0;
    }
}

bool isPalindrome(int argument_int) {
    auto integer = std::to_string(argument_int);
    std::string rev_int(integer);
    std::reverse(rev_int.begin(), rev_int.end());
    if (integer == rev_int) {
        return 1;
    }
    else {
        return 0;
    }
}