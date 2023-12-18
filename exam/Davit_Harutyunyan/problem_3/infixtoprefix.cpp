#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>


bool isOperator(char c);
int precedence(char Operator);
std::string convertInfixToPrefix(std::string& infix);


int main() {
    std::string infixExpr;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, infixExpr);

    std::string prefixExpr = convertInfixToPrefix(infixExpr);
    std::cout << "Prefix expression: " << prefixExpr << std::endl;

    return 0;
}


bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


int precedence(char Operator) 
{
    if (Operator == '+' || Operator == '-') 
    {
        return 1;
    } 
    else if (Operator == '*' || Operator == '/') 
    {
        return 2;
    }
    return 0;
}

std::string convertInfixToPrefix(std::string& infix) 
{
    std::string prefix;
    std::stack<char> operators;
    std::string reversedInfix = infix;
    
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    for (char c : reversedInfix) 
    {
        if (isalnum(c)) 
        {
            prefix += c;
        } 
        else if (c == ')') 
        {
           operators.push(c);
        } 
        else if (c == '(') 
        { 
            while (!operators.empty() && operators.top() != ')') 
            {
                prefix += operators.top();
                operators.pop();
            }
            
            operators.pop();
        } 
        else if (isOperator(c)) 
        {
           
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) 
            {
                prefix += operators.top();
                operators.pop();
            }
        
            operators.push(c);
        }
    }

    while (!operators.empty()) 
    {
        prefix += operators.top();
        operators.pop();
    }

  
    std::reverse(prefix.begin(), prefix.end());

    return prefix;
}
