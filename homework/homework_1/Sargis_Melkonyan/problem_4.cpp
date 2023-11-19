/*4. Design and implement the algorithm of greatest common divisor 
 and lowest common multiple using <code>primeFactorize</code> function:
    ```
    int computeGCD(int a, int b);
    int computeLCM(int a, int b);
    ```
*/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

std::vector<int> primeFactorize(int);
int input(std::string); 
int computeGCD(int, int);
int computeLCM(int, int);


//type alias 
using intList = std::vector<int>;

int main(){
    const auto x = input("x = ");
    const auto y = input("y = ");
    
    auto gcd = computeGCD(x, y);
    auto lcm = computeLCM(x, y);

    std::cout<<"GCD = "<< gcd << std::endl;
    std::cout<<"LCM = "<< lcm << std::endl;
    return 0;
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

int input(std::string msg) {
    int value;
    std::cout << msg ;
    std::cin >> value;

    return value;    
}


int computeGCD(int a, int b){
    int gcd = 1;

    auto a_pr_fact = primeFactorize(a); 
    auto b_pr_fact = primeFactorize(b); 

    for(int i = 0; i < a_pr_fact.size(); i++){
        if(std::count(b_pr_fact.begin(),b_pr_fact.end(),a_pr_fact[i])){
            gcd *= a_pr_fact[i];
            std::vector<int>::iterator it;                                  // ???
            it = remove(b_pr_fact.begin(), b_pr_fact.end(), a_pr_fact[i]);
        }
    }

    return gcd;
}

int computeLCM(int a, int b){
    int gcd = 1;
    int lcm = 1;

    auto a_pr_fact = primeFactorize(a); 
    auto b_pr_fact = primeFactorize(b); 

    for(int i = 0; i < a_pr_fact.size(); i++){
        if(std::count(b_pr_fact.begin(),b_pr_fact.end(),a_pr_fact[i])){
            gcd *= a_pr_fact[i];
            std::vector<int>::iterator it;                                  // ???
            it = remove(b_pr_fact.begin(), b_pr_fact.end(), a_pr_fact[i]);
        }
    }

    lcm = a*b/gcd;
    return lcm;
}