#include <iostream>
#include <string>
#include <vector>
bool isPalindrome(const std::string&);
bool isPalindrome(int);
int main() {
    std::string text;
    int dig;
    std::cin>>text>>dig;
    if(isPalindrome(text)) {
        std::cout<<"Text is palindrome"<<std::endl;
    }
    else {
        std::cout<<"Text is not palindrome"<<std::endl;
    }
    if(isPalindrome(dig)) {
        std::cout<<"Digit is palindrome"<<std::endl;
    }
    else {
        std::cout<<"Digit is not palindrome"<<std::endl;
    }
}
bool isPalindrome(const std::string& text) {
    int count=0;
    for(int i=0;i<text.size()/2;++i) {
        if(text[i]==text[text.size()-1-i]) {
            ++count;
        }
    }
    if(count==text.size()/2) {
        return 1;
    }
    else {
        return 0;
    }
}
bool isPalindrome(int dig) {
    int rem,count=0;
    std::vector<int> vect;
    while(dig/10 != 0) {
        rem=dig%10;
        dig/=10;
        vect.push_back(rem);
    }
    vect.push_back(dig);
    for(int i=0;i<vect.size()/2;++i) {
        if(vect[i]==vect[vect.size()-1-i]) {
            ++count;
        }
    }
    if(count==vect.size()/2) {
        return 1;
    }
    else {
        return 0;
    }
}


    
    
