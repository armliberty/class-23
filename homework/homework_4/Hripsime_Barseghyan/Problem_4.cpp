#include <iostream>
#include <string>
#include <algorithm> 

bool isPalindrome(const std::string&);
bool isPalindrome(int);

template <typename T>
T input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;

    return value;
}


int main(){
    const auto word = input<std::string>("Enter a word");
    const auto number = input<int>("Enter a number");

    if(isPalindrome(word))
        std::cout << "The word is Palindrome." <<std::endl;
    else
        std::cout << "The word is not Palindrome." <<std::endl;
    
    if(isPalindrome(number))
        std::cout << "The number is Palindrome." <<std::endl;
    else
        std::cout << "The number is not Palindrome." <<std::endl;

    return 0;
}



bool isPalindrome(const std::string& word){
    std::string str = word; 
    std::string str1 = str;
    std::reverse(str.begin(), str.end()); 

    return (str1 == str);
}


bool isPalindrome(int number){
    std::string num = std::to_string(number); 
    std::string num1 = num;
    std::reverse(num.begin(), num.end()); 

    return (num1 == num);
}