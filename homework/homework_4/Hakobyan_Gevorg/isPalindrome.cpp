#include <iostream>
#include <string>
#include <vector>

std::pair<bool,int> isPalindrome(int);
std::pair<bool, int> isPalindrome(const std::string&);
template <typename T>
void printAnswer(std::pair<bool, int>, T);

int main() {
    int num;
    std::cout << "Input the number: ";
    std::cin >> num;
    printAnswer(isPalindrome(num),num);

    std::string text;
    std::cout << "Input the text: ";
    std::cin >> text;
    printAnswer(isPalindrome(text), text);
    return 0;
}

template <typename T>
void printAnswer(std::pair<bool, int> answer,T num) {
    const auto [is_Palindrome, index1] = answer; 
    if (is_Palindrome) {
        std::cout << num << " is a palindrome" << "\n";
        return;
    } 
    int index2;
    if constexpr (std::is_same_v<T, int>) {
        std::string textNum = std::to_string(num);
        index2 = (textNum.size() -1) - index1;
    }
    if constexpr (std::is_same_v<T, std::string>) {
        index2 = (num.size() -1) - index1;
    }

    std::cout << num << " is not a palindrome" << "\n"; 
    std::cout << std::string(index2, ' ');
    std::cout << '^';
    std::cout << std::string(index1 - index2 - 1, ' ');
    std::cout << '^' << "\n";
}

std::pair<bool, int> isPalindrome(int num) {
    std::vector<int> elems;

    int elem;
    while(num) {
        elem = (num % 10);
        elems.push_back(elem);
        num = (num / 10);
    }

    for (int i = 0; i < (elems.size() / 2); ++i) {
        int j = elems.size() - 1 - i;
        if (elems[i] != elems[j]) {
           return {false, j};
        }
    }
    return {true, 0};
}

std::pair<bool, int> isPalindrome(const std::string& text) {
    for (int i = 0; i < text.size() / 2; ++i) {
        int j = text.size() - 1 - i;
        if (text[i] != text[j]) {
            return {false, j};
        }
    }
    return {true, 0};
}
