#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string&);

int main(){
    std::string pattern;
    std::cout<<"Input pattern:";
    std::cin>>pattern;
    
    if(isPalindrome(pattern)){
        std::cout<<"Pattern is palindrome";
    }
    else std::cout<<"Pattern is not palindrome";
    
    
}

bool isPalindrome(const std::string& pattern){
    auto p = pattern;
    
    std::reverse(p.begin(), p.end());
    
    if(p == pattern) return true;
    else return false;
}
