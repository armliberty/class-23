#include <iostream>
#include <vector>
#include <map>


int computeGCD(int a, int b);
int input(std::string msg);
bool isPrime(int x);
std::vector<int> primeFactorize(int); 
void print(std::vector<int>); 



int main(){
    int a = input("Insert first number");
    int b = input("Insert second number");
    int gcd = computeGCD(a, b);
    std::cout <<"GCD of inserted numbers: " <<gcd << std::endl;
    return 0;
}


int computeGCD(int a, int b){
    std::cout << a << " = ";
    print(primeFactorize(a));
    std::cout << b << " = ";
    print(primeFactorize(b));

    std::map<int, int> duplicates_a;
    std::map<int, int> duplicates_b;
    std::vector<int> GCD;

    for (const int num : primeFactorize(a)) 
        duplicates_a[num]++;
    
    for (const int num : primeFactorize(b)) 
        duplicates_b[num]++;


    for (const auto pair_a : duplicates_a) {
        for (const auto pair_b : duplicates_b){
            if (pair_a.first == pair_b.first) {
                if (pair_a.second <=  pair_b.second)
                    for (int i = 0; i < pair_a.second; i++)
                        GCD.push_back(pair_a.first);
                else
                    for (int i = 0; i < pair_b.second; i++)
                        GCD.push_back(pair_a.first);
            }    
        }
    }

    int gcd = 1;
    for (const int i : GCD) 
        gcd *= i ;
    
    return gcd;
}



std::vector<int> primeFactorize(int x){
    std::vector<int> factors = {};

    if(isPrime(x)){
        factors.push_back(x);
        return factors;
    }
    else{
         while (x % 2 == 0)
        {
            factors.push_back(2);
            x /= 2;
        }

        for (int i = 3; i <= x; i += 2)
            if(x % i == 0){
                factors.push_back(i);
                x /= i;
                i -= 2;
            }
        
        return factors;
    }
}


void print(std::vector<int> factors){
    std::map<int, int> duplicate;
  
    for (const int num : factors) 
        duplicate[num]++;
    

    size_t total_pairs = duplicate.size();
    size_t current_pair = 0;

    for (const auto pair : duplicate) {
        std::cout << pair.first << "^" << pair.second;
        if (++current_pair < total_pairs) 
            std::cout << " * ";
    }
    
    std::cout << std::endl;
    //return duplicate;
} 


int input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    double value;
    do
    {
        std::cin >> value;
        if(value <= 0)  std::cout <<  "Please insert a positive number: "; 
    } while (value <= 0);
    
    return value;
}


bool isPrime(int x){
    bool t = true;
    for (int i = 2; i < x/2; i++)
        if(x % i == 0){
            t = false;
            return t;
        }

    return t;
}