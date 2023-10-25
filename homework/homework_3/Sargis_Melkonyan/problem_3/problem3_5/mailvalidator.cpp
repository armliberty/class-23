/*
  5. Implement the DFA in a C++ program that validates e-mail addresses.
*/

#include <iostream>
#include <limits>
#include <string>
#include <vector>


// ALIAS
using StaseId = int;
using StateIds = std::vector<StaseId>;
using Matrix = std::vector<StateIds>;



std::string input(std::string& msg);


int main(){
    const auto email = input("input email: ");
    if(validator(email)){
        std::cout<<email<<" is valid";
    }else {
        std::cout<<email<<"isn't vaid";
    }
 
    return 0;
}


std::string input(std::string msg){
    if(msg.empty()){
        std::cout<<": ";
    }
    std::string value;
    std::cout<<msg;
    std::cin>>value;
    return value;
}


bool validator(std::string mail){
    

    for(int i:mail){

    }
}

Matrix TrMatrix(){
    StaseId alphabetsize = std::numeric_limits<char>::max();
}