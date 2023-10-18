#include <iostream>
#include <vector>
#include <string>
bool isPalindrome(const std::string&);
bool isPalindrome(int);
int main() {
    std::string text;
    int dig;
    std::cin>>text>>dig;
    if(isPalindrome(text)) {
        std::cout<<"Is palindrome"<<std::endl;
    }
    else {
        std::cout<<"Is not palindrome"<<std::endl;
    }
    if(isPalindrome(dig)) {
        std::cout<<"Is palindrome"<<std::endl;
    }
    else {
        std::cout<<"Is not palindrome"<<std::endl;
    }
}
bool isPalindrome(const std::string& text) {
    int count=0;
    for(int i=0;i<text.size()*0.5;++i) {
        if(text[i]==text[text.size()-1-i]) {
            ++count;
        }
    }
    if(count==text.size()*0.5) {
        return 1;
    }
    else {
        return 0;
    }
}
bool isPalindrome(int dig) {
    int rem,count=0;
    std::vector<int> vector;
    while(dig/10 != 0) {
        rem=dig%10;
        dig/=10;
        vector.push_back(rem);
    }
    vector.push_back(dig);
    for(int i=0;i<vector.size()*0.5;++i) {
        if(vector[i]==vector[vector.size()-1-i]) {
            ++count;
        }
    }
    if(count==vector.size()*0.5) {
        return 1;
    }
    else {
        return 0;
    }
}