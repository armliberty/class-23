#include <iostream>

void input(std::string& str)
{
    std::cout << "Enter email to verify: " << std::endl;
    std::cin >> str;
}

int is_alpha(int c)
{
    if (c >= 'A' && c <= 'z')
        return (1);
    return 0;
}

int is_valid_char(int c)
{
    if (is_alpha(c)  c == '_'  (c >= '0' && c <= '9')  c == '-'  c == '.')
        return (1);
    return (0);
}

bool check(std::string& str)
{
    bool check = false;
    int i = -1;

    if(is_alpha(str[0]))
    {
        while (str[++i] && is_valid_char(str[i]) && str[i] != '@');
        if (str[i] == '@')
            while (str[++i] && is_alpha(str[i]) && str[i] != '.');
        if (str[i] == '.')
            if (str[i + 1] && str[i + 2] && str[i + 3] && is_alpha(str[i + 1]) && is_alpha(str[i + 2]) && is_alpha(str[i + 3]))
                return (1);
    }
    return (0);
}

int main()
{
    std::string input_str;
    input(input_str);
    std::cout << "result is: " << check(input_str) << std::endl;
}
