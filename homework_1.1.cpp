#include<cmath>
#include<iostream>

long double getSqrt(double, long double);

int main()
{
    int num;
    std::cout << "Input the number: ";
    std::cin >> num;

    std::cout << "Sqrt(" << num << ") = " << getSqrt(num, 0.0000001) << "\n";
    return 0;
}


long double getSqrt(double num, long double delta = 0.00001) 
{
    long double x {num};
    long double root;
    while(true) {
        root = 0.5 * (x + (num / x));
        if (abs(root - x) < delta) {
            break;
        }
        x = root;
    }
    return root;
}


