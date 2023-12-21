#include <iostream>

void input(std::string& str);
int is_alpha(int c);
int is_valid_char(int c);
bool check(std::string& str);

int main()
{
    std::string input_str;
    input(input_str);
    if (check (input_str))
        std::cout << "This is " <<std::endl;
    else
        std::cout << "This isn`t " <<std::endl;

}

void input(std::string& str)
{
    std::cout << "expression: " << std::endl;
    std::cin >> str;
}

int is_alpha(int c)
{
    if (c >= 'A' && c <= 'z')
        return 1;
    return 0;
}

int is_valid_char(int c)
{
    if (is_alpha(c) || c == 'a' || c== 'b')
        return 1;
    return 0;
}

bool check(std::string& str){
    bool check = false;
    int i = -1, k=0;

    if(is_alpha(str[0]) && k<str.size()){
        while (str[++i] && is_valid_char(str[i]) != 'b'){
            if (str[++k]=='a' && str[k]!='a')       
            return 1;
        }  
        return 0;
    }
}