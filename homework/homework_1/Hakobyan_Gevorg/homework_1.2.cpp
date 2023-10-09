#include<cmath>
#include<iostream>

bool isPrime(int);
bool hasPerfectSquare(double, long double);

int main() {
    int num;
    std::cout << "Input the number: ";
    std::cin >> num;

    bool answer = isPrime(num);
    if (answer) {
        std::cout << "Number is prime!" << "\n";
        return 0;
    }

    std::cout << "Number is not prime" << "\n";
    return 0;
}

bool isPrime(int num) {
    if (hasPerfectSquare(num, 0.000001)) {
        return false;
    }

    for (int i = 2; i < num / 2; ++i) { 
        if (!(num % i)) {
            return false;
        }
    }
    return true;
}

bool hasPerfectSquare(double num, long double delta) {
    long double x {num};
    long double root;
    while(true) {
        root = 0.5 * (x + (num / x));
        if (abs(root - x) < delta) {
            break;
        }
        x = root;
    }

    if (root - int(root) < 0.1) {
        return true;
    }
    return false;
}


