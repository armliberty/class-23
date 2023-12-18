#include <iostream>  
#include <stack>  
#include <algorithm>  
  
bool is_oper(char c);  
int precedence(char op);  
std::string infix_to_prefix(std::string& infix);  
  
  
int main() {  
    std::string infixExpr;  
    std::cout << "infix";  
    std::getline(std::cin, infixExpr);  
  
    std::string prefixExpr = infix_to_prefix(infixExpr);  
    std::cout << "prefix" << prefixExpr << std::endl;  
  
    return 0;  
}  
  
  
bool is_oper(char x)  {  
    return (x == '+'    x == '-'    x== '*'  x== '/');  
}  
  
int precedence(char op)  {  
    if (op == '+' || op == '-')  {  
        return 1;  
    }   
    else if (op == '*' || op == '/')  {  
        return 2;  
    }  
    return 0;  
}  
  
std::string infix_to_prefix(std::string& infix){  
    std::string prefix;  
    std::stack<char> operators;  
    std::string reversInfix = infix;  
      
    std::reverse(reversInfix.begin(), reversInfix.end());  
  
    for (char c : reversInfix)   {  
        if (isalnum(c))    {  
            prefix += c;  
        }   
        else if (c == ')')     {  
           operators.push(c);  
        }   
        else if (c == '(')   {   
            while (!operators.empty() && operators.top() != ')')  {  
                prefix += operators.top();  
                operators.pop();  
            }        
            operators.pop();  
        }   
        else if (is_oper(c))   {  
             
            while (!operators.empty() && precedence(operators.top()) >= precedence(c))   {  
                prefix += operators.top();  
                operators.pop();  
            }   
            operators.push(c);  
        }  
    }  
  
    while (!operators.empty())  {  
        prefix += operators.top();  
        operators.pop();  
    }  
  
    
    std::reverse(prefix.begin(), prefix.end());  
  
    return prefix;  
}