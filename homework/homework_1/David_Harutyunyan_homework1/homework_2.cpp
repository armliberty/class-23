#include <iostream>
 
bool isPrime(int n);

int main()
{
    int count;
    std::cout<<"count: ";
    std::cin>>count;
    for(int i = 1; i <= count; i++)
        {
            std::cout<<std::boolalpha<<"number "<<i<<" "<<isPrime(i)<<std::endl;
        }
    return 0;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 