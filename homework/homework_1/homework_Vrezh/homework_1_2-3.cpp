#include<cmath>
#include<iostream>
#include<vector>
 
bool isPrime(int n)
{
    if (n <= 1){
        std::cout<<"the number is not prime"<<std::endl;
        return false;
    }
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0){
            std::cout<<"the number is not prime"<<std::endl;
            return false;
        }
    std::cout<<"the number is prime"<<std::endl;
    return true;
}
std::vector<int> primeFactors(int n)
{
    std::vector<int> ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n=n/i;
        }

    }
     if (n > 2){
        ans.push_back(n);
     }
    return ans;
}

int main(){
    int num ;
    std::cout<<"enter number"<<std::endl;
    std::cin>>num;
    isPrime(num);
    auto ans = primeFactors(num);
    for(int i = 0; i<ans.size();i++){
        std::cout<<ans[i]<<" ";
    }
   std::cout<<std::endl; 
}
