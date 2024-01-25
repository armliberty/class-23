#include <cstring>
#include <iostream>
#include <vector>


bool isPalindrome(const std::string&);
std::string Input() ;


int main() {
        std::string str;
    std::cin>>str;
        if(!isPalindrome(str))
            std::cout<<str<<":is not Palidrome string"<<std::endl;
        else 
            std::cout<<str<<":is Palidrome string"<<std::endl;
   
 }   





bool isPalindrome(const std::string& str){
     std::vector<char> str1 ;
     std::vector<char> str2 ;
     auto k=0;
    if(str.size()%2==0){
        for (int i=0; i<str.size()/2; ++i)
           { str1[i]=str[i];
            std::cout<<str1[i]<<std::endl;
        }
        std::cout<<std::endl;
        for (int i=str.size()-1; i>(str.size()/2)-1; --i)
            {str2[k]=str[i];
            std::cout<<str2[k++]<<std::endl;}
    }        
    else{
        for (int i=0; i<str.size()/2+1; ++i)
           { str1[i]=str[i];
            std::cout<<str1[i]<<std::endl;
        }
        std::cout<<std::endl;
        for (int i=str.size()-1; i>(str.size()/2)-1; --i)
            {str2[k]=str[i];
            std::cout<<str2[k++]<<std::endl;}

    }   
    int l=0;
   for(int i=0;i<str1.size();i++){
        if(str1[i]==str2[i])
            k++;
        if(l==str1.size())
            return 0;
        else 
            return 1;
   }     
}     


