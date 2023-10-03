#include <iostream>
#include <cmath>

double sine(double x, double delta = 0.0001) {
    double value = x;
    double preValue;
    int i = 0;

    while(1)
	{
		double y = std::sin(value) - value;
		double yprime = std::cos(value) - 1;
		if (std::abs(y) < delta){
            std::cout << "Newton's method : "<<value<<std::endl;
            return (value);
        }
		value = value - y / yprime;
		std::cout<<"X_n+"<<++i<<" = "<<value<<std::endl;

	}
    
	return (0);
}

int main() {

    sine(1);
    
}

