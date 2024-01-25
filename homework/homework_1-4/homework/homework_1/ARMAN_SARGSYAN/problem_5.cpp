#include <iostream>

int euclidGcd(int num1,int num2){
	if (num1 == 0) 
		return num2; 
	if (num2 == 0) 
		return num1;
	if( num1 == num2 ){
		return num1;
	}
    int b = 0;
    if( num1 > num2 ){
        b = num1 - num2;
        euclidGcd( b, num2);
    } else {
        euclidGcd( num2, num1 ); 
	};
}
int euclidLcm(int num1, int num2) {
    return (num1 * num2) / euclidGcd( num1, num2 );
}
int main() {
    int num1,num2;
    std::cin >> num1 >> num2;
    std::cout << "gcd is "<< euclidGcd(num1, num2) <<std::endl;
    std::cout << "lcd is " << euclidLcm(num1, num2) <<std::endl;
}
