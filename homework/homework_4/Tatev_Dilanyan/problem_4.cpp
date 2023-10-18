#include <iostream>
#include <string>

template <typename T>
T input(const std::string& prompt) {
    T userInput;
    std::cout << prompt;
    std::cin >> userInput;
    return userInput;
}

char toLower(char c);
bool isPalindrome(const std::string& str);
bool isPalindrome(int num);

int main() {
    std::string str = input<std::string>("Enter a string:: ");
    if (isPalindrome(str)) {
        std::cout << "String is a palindrome" << std::endl;
    } else {
        std::cout << "String isn't palindrome." << std::endl;
    }

    int num = input<int>("Enter an integer:: ");

    if (isPalindrome(num)) {
        std::cout << "Number is a palindrome!" << std::endl;
    } else {
        std::cout << "Number isn't a palindrome." << std::endl;
    }


    return 0;
}

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        char leftChar = toLower(str[left]);
        char rightChar = toLower(str[right]);

        if (!isalnum(leftChar)) {
            left++;
            continue;
        }

        if (!isalnum(rightChar)) {
            right--;
            continue;
        }

        if (leftChar != rightChar) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

bool isPalindrome(int num) {
    if (num < 0) {
        return false; 
    }

    int original = num;
    int reverse = 0;

    while (num > 0) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }

    return original == reverse;
}
