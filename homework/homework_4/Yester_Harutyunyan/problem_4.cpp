#include <iostream>
#include <string>
#include <vector>
bool isPalindrome(const std::string&);
bool isPalindrome(int);
template <typename T>
void print(bool ans,T value);
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
    const auto text = input<std::string>("Input the string to check");
    const auto digit = input<int>("Input the number to check");
    print(isPalindrome(text),text);
    print(isPalindrome(digit),digit);
}

template <typename T>
void print(bool ans, T value) {
    if (ans) { 
		std::cout << value << " "
			<< "is palindrome" << std::endl; 
	} 
	else { 
		std::cout << value << " "
			<< "is not palindrome" << std::endl; 
	} 
}

bool isPalindrome(const std::string& text) {
    int count = 0;
    int textSize;
    if (text.size() % 2 == 0){
       textSize = text.size(); 
    } else {
       textSize = text.size() + 1;
    }

    for (int i = 0; i < textSize/2; ++i){
        if (text[i] == text[(text.size()-1) - i]){
            count ++;
        }
    }

    if (count == textSize/2){
        return 1;
    } else {
        return 0;
    }
}

bool isPalindrome(int digit) {
    if (digit < 0) {
        return 0;
    }
    int number = digit;
    int remainder;
    int reverse;
    while (number != 0) {
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number /= 10;
    }
    return digit == reverse; 
}