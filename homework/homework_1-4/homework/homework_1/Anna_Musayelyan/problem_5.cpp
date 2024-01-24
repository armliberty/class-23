#include <iostream>

int calculateGCD(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int calculateLCM(int num1, int num2) {
    int gcd = calculateGCD(num1, num2);
    return (num1 * num2) / gcd;
}

int main() {
    int num1, num2;

    std::cout << "Enter two positive integers: ";
    std::cin >> num1 >> num2;

    if (num1 < 0 || num2 < 0) {
        std::cout << "Please enter positive integers." << std::endl;
        return 1;
    }

    int gcd = calculateGCD(num1, num2);
    int lcm = calculateLCM(num1, num2);

    std::cout << "GCD of " << num1 << " and " << num2 << " using Euclid's algorithm is: " << gcd << std::endl;
    std::cout << "LCM of " << num1 << " and " << num2 << " using Euclid's algorithm is: " << lcm << std::endl;

    return 0;
}
