#include <iostream>
#include <string>
#include <vector>

std::pair<bool,int> isPalindrome(int);
std::pair<bool, int> isPalindrome(const std::string&);


int main() {
    int intarg;
    std::cout << "Input the integer: "; std::cin >> intarg;
    if(isPalindrome(intarg).first){
        std::cout<<intarg<<" : is palindrome";
    } else {
        std::cout<<intarg<<" : isn't palindrome";
    }

    std::string strarg;
    std::cout << "\nInput the string: "; std::cin >> strarg;
    if(isPalindrome(strarg).first){
        std::cout<<strarg<<" : is palindrome\n";
    } else {
        std::cout<<strarg<<" : isn't palindrome\n";
    }
    return 0;
}


std::pair<bool, int> isPalindrome(int num) {
    std::vector<int> list;

    int instans, i, j;
    while(num) {
        instans = (num % 10);
        list.push_back(instans);
        num = (num / 10);
    }

    for (i = 0; i < (list.size() / 2); ++i) {
        j = list.size() - 1 - i;
        if (list[i] != list[j]) {
           return {false, j};
        }
    }
    return {true, 0};
}

std::pair<bool, int> isPalindrome(const std::string& text) {
    int i, j;
    
    for (i = 0; i < text.size() / 2; ++i) {
        j = text.size() - 1 - i;
        if (text[i] != text[j]) {
            return {false, j};
        }
    }
    return {true, 0};
}