#include <iostream>

bool isPalindrome(int);

int main()

{

     int number;



     std::cout << "Enter a positive number: ";

     std::cin >> number;



     if (isPalindrome(number))

         std::cout << " The number is a palindrome.";

     else

         std::cout << " The number is not a palindrome.";



    return 0;

}

bool isPalindrome(int number){

     int n, remainder, rev = 0;

     n = number;



     do

     {

         remainder = number % 10;

         rev = (rev * 10) + remainder;

         number = number / 10;

     } while (number != 0);





     if (n == rev)

         return true;

     else

         return false;

}
