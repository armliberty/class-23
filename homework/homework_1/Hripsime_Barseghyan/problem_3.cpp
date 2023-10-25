#include <iostream>
#include <vector>
#include <map>

int input(std::string msg);
bool isPrime(int x);
std::vector<int> primeFactorize(int); 
void print(std::vector<int>); 


int main(){
    int x = input("Insert a positive number");
    if(x == 1 || x == 0){
        std::cout <<  "Inserted number is neither prime nor composite." << std::endl;
        return 0;
    }

    std::cout << "Factors of inserted number: ";
    for (const int i : primeFactorize(x)) {
            std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << x << " = ";
    print(primeFactorize(x));

    return 0;
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
    

    // for (int num = 0; num < factors.size(); num++) {
    //     int value = factors[num];
    //     duplicate[value]++;
    // }

    
    int total_pairs = duplicate.size();
    int current_pair = 0;

    for (const auto pair : duplicate) {
        std::cout << pair.first << "^" << pair.second;
        if (++current_pair < total_pairs) 
            std::cout << " * ";
    }
    
    std::cout << std::endl;
} 


int input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    double value;
    do
    {
        std::cin >> value;
        if(value < 0)  std::cout <<  "Please insert a positive number: "; 
    } while (value < 0);
    
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