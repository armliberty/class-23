#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

bool isPalindrome(int number) {
    std::string numStr = std::to_string(number);
    return isPalindrome(numStr);
}

template <typename T>
T input(const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;
    return value;
}

int main() {
    const auto word = input<std::string>("Enter a word");
    const auto number = input<int>("Enter a number");

    if (isPalindrome(word))
        std::cout << "Palindrome word." << std::endl;
    else
        std::cout << "Non palindrome word." << std::endl;

    if (isPalindrome(number))
        std::cout << "Palindrome number." << std::endl;
    else
        std::cout << "Non palindrome number." << std::endl;

    return 0;
}