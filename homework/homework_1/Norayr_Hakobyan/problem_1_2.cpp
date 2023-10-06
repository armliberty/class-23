#include <iostream>

bool Prime_num (int n)
{
    if(n <= 1)
    return false;

    for(int i = 2; i <= n / 2; i ++)
    if(n % i == 0)
    return false;
    else 
    return true;

}

int main() 
{
    int l;
    std::cout<<"l=";
    std::cin>>l;
    for(int i = 1; i < l+1; i ++)
    {
        std::cout << std::boolalpha << "l=" << i << Prime_num(i) << std::endl;
    }

    return 0;
}
