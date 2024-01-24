#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string&);
std::string input() {
    std::string value;
    std::getline(std::cin, value);
    return value;
}


int main() {
        const auto str=input();
        if(!isPalindrome(str))
            std::cout<<str<<":is not Palidrome string"<<std::endl;
        else 
            std::cout<<str<<":is Palidrome string"<<std::endl;
        
 }   

 
bool isPalindrome(const std::string& str){
    if(str.size()%2==0)
      return 0 == str.compare(0, str.size()/2-1, str,str.size()/2, str.size()-str.size()/2 );
    else
      return 0 == str.compare(0, str.size()/2,str, str.size()/2,str.size()-str.size()/2 );    
}
