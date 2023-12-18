//Artashes Yeritsyan

#include <iostream> 
#include <stack> 
#include <algorithm> 
 
bool isOperator(char c); 
int priority(char op); 
 
std::string convertInfixToPrefix(const std::string& infixExpr)  
{ 
    std::string prefix;
    std::string reversedInfix = infixExpr;
    std::stack<char> operators; 
     
    std::reverse(reversedInfix.begin(), reversedInfix.end()); 
 
    for (int i = 0; i < reversedInfix.size(); ++i)
    {
        if (isalnum(reversedInfix[i]))  
        { 
            prefix += reversedInfix[i];
        }  
        else if (isOperator(reversedInfix[i]))  
        {             
            while (!operators.empty() && priority(operators.top()) >= priority(reversedInfix[i])) { 
                prefix += operators.top(); 
                operators.pop(); 
            } 
         
            operators.push(reversedInfix[i]); 
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

bool isOperator(char c)  
{ 
    return (c == '+' || c == '-' || c == '*' || c == '/'); 
} 
 
int priority(char op)  
{ 
    if (op == '+' || op == '-')  
    { 
        return 1; 
    }  
    else if (op == '*' || op == '/')  
    { 
        return 2; 
    } 
    return 0; 
} 