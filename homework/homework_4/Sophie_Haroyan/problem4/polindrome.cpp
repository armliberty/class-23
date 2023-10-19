#include <iostream>
#include <string>


bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; 
        }
        left++;
        right--;
    }

    return true; 
}


bool isPalindrome(int num) {
    std::string str = std::to_string(num);
    return isPalindrome(str);
}

int main() {
    // Test cases
    std::string str;
    int digit;
    std:: cout << "input string::";
    std:: cin >> str;
    std:: cout << "input digit::";
    std:: cin >> digit;
    

    if (isPalindrome(str)) {
        std::cout << str << "- is a palindrome." << std::endl;
    } else {
        std::cout << str << "- is not a palindrome." << std::endl;
    }


    if (isPalindrome(digit)) {
        std::cout << digit << " is a palindrome." << std::endl;
    } else {
        std::cout << digit << " is not a palindrome." << std::endl;
    }

    return 0;
}

