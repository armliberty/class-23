/*
3. Extend the algorithm of <code>isPrime</code> to return the prime factorization of an integer:
    ``` std:::vector<int> primeFactorize(int); ```
*/

#include <iostream>
#include <string>
#include <vector>

//description of functions
int input(std::string);
std::vector<int> primeFactorize(int);
void vecOut(std::vector<int>);

//type alias
using intList = std::vector<int>;

int main(){
    const auto number = input("inpt number: ");
    auto finalList = primeFactorize(number);
    vecOut(finalList);

    return 0;
}

int input(std::string msg) {
    int value;
    std::cout << msg ;
    std::cin >> value;

    return value;    
}

std::vector<int> primeFactorize(int number){ 
    intList pr_fact;

    for(int i = 2; i<=(number/2); i++){
        while(number % i == 0){
            number = number/i;
            pr_fact.push_back(i);
        }
    }
    
    if(pr_fact.size() == 0)
        pr_fact.push_back(1);
        pr_fact.push_back(number);
    
    return pr_fact; 
}

void vecOut(std::vector<int> vecName){
    std::cout<<"Prime Factorize: ";
    for(int i = 0; i < vecName.size(); ++i)
        std::cout<<vecName[i]<<", ";
    std::cout<<std::endl;
}
