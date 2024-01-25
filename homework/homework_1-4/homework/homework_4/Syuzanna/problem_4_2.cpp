#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string&);
bool isPalindrome(int);
   ```
int main() {
        const auto str=input<std::string>("Input string");
        if(!isPalidrome(str))
            std::cout<<str<<":is not Palidrome string"<<std::endl;
        else 
            std::cout<<str<<":is Palidrome string"<<std::endl;
        int d; std::cin>>d;    
        const int digit=d; std::cout<<"Input digit"<<std::endl;
        if(!isPalidrome(d))
            std::cout<<d<<":is not Palidrome digit"<<std::endl;
        else 
            std::cout<<d<<":is Palidrome digit"<<std::endl;
    
 }   

 std::string input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::getline(std::cin, value);
    return value;
}

bool isPalindrome(const std::string& str){
    if(str.size()%2==0)
        str.compare(str.begin(), (str.size()/2)-1, str.end()-1,str.size()/2 );
    else
        str.compare(str.begin(), str.size()/2, str.end()-1,str.size()/2 );    
}
bool isPalindrome(int d){




}