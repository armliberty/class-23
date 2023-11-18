#include <iostream>
#include <algorithm>
#include <numeric>


int GCD(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int calculateMeasures(int a, int b, int c, int d) 
{
    int commonDen = (b * d) / GCD(b, d);

    int A = commonDen / b;

    int C = commonDen / d;

    return std::min(A, C);
}

int main() 
{
    int a, b, c, d;
    std::cout << "Enter (a/b): ";
    std::cin >> a >> b;
    std::cout << "Enter (c/d): ";
    std::cin >> c >> d;

    int measures = calculateMeasures(a, b, c, d);

    std::cout << a << "/" << b << " и " << c << "/" << d << measures << std::endl;

}
