#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string&);
bool isPalindrome(int);

int main() {
    std::string str;
    int num;
    std::cout << "Enter a number ";
    std::cin >> num;
    std::cout << "Enter a string ";
    std::cin >> str;
    if (isPalindrome(num)) {
        std::cout << "The number is a palindrome\n";
    }
    else {
        std::cout << "The number is not a palindrome\n";
    }
    if (isPalindrome(str)) {
        std::cout << "The string is a palindrome\n";
    }
    else {
        std::cout << "The string is not a palindrome\n";
    }

}

bool isPalindrome(const std::string& str) {
    int start = 0;
    int end = str.size() - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isPalindrome(int num) {
    std::vector<int> digits;
    int digit;
    while (num > 0) {
        digit = (num % 10);
        digits.push_back(digit);
        num = (num / 10);
    }
    int start = 0;
    int end = digits.size() - 1;
    while (start < end) {
        if (digits[start] != digits[end]) {
            return false;
        }
        start++;
        end--;
    }
}
