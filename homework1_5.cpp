#include<iostream>

int GCD(int, int);
void LCM(int, int, int);
std::pair<int, int> Max(int, int);
bool validateNumbers(int, int);
    
int main() {
    int num1, num2;
    std::cout << "Input numbers: ";
    std::cin >> num1 >> num2;
    bool validate = validateNumbers(num1, num2);

    //if no 0(s)
    if (validate) {
        int gcd =  GCD(num1, num2);
        LCM(num1, num2, gcd);
        return 0;
    }

    std::cout << "Error 1: Invalid number(s)" << "\n";
    return 0;
}

//GCD function
int GCD(int num1, int num2) {
    std::pair<int, int> max_min = Max(num1, num2);
    auto min = max_min.second;
    auto max = max_min.first;
    if (0 == max % min) {
        std::cout << "GCD of " << max << " and " << min << ": " << min << "\n";
        return min;
    }
    
    std::cout << "GCD of " << max << " and " << min << ": ";
    int temp {0};
    int gcd {max};
    while(min) {
        temp = gcd;
        gcd = min;
        min = (temp % min);
    }

    std::cout << gcd << "\n";
    return gcd;
}

//LCM function
void LCM(int num1, int num2, int GCD) {
    int lcm = (num1 * num2) / GCD;
    std::cout << "lcm of " << num1 << " and " << num2 << ": " << lcm << "\n";
}

//find the maximum and minimum 
std::pair<int, int> Max(int num1, int num2) {
    std::pair<int, int> max_min;

    if (num1 > num2) {
        max_min.first = num1;
        max_min.second = num2;
        return max_min;
    } 

    max_min.first = num2;
    max_min.second = num1;
    return max_min;
}

//Validate numbers(finding 0(s))
bool validateNumbers(int num1, int num2) {
    if (0 == num1 || 0 == num2) {
        return false;
    }

    return true;
}


