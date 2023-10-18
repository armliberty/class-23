#include <iostream>

bool isPalindrome(const std::string& str)
{
    int size = str.size();
    int i = 0;
    int j = size - 1;

    while (str[i] == str[j] && i != j && i < size / 2 && j >= size / 2)
    {
        i++;
        j--;
    }
    if (i == j)
        return (1);
    return (0);
}

bool isPalindromeInt(int x)
{
    std::string tostr = std::to_string(x);
    if (isPalindrome(tostr))
        return (1);
    return (0);
}

int main()
{
    std::cout << isPalindrome("Anna") << std::endl;
}
