#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isOperator(char c) {
    return (c == '+' ||  c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string convertInfixToPrefix(const std::string& infixStr) {
    std::stack<char> operators;
    std::string postfix;

    std::string reversedInfix = infixStr;
    std::reverse(reversedInfix.begin(), reversedInfix.end());

    for (char c : reversedInfix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == ')') {
            operators.push(c);
        } else if (c == '(') {
            while (!operators.empty() && operators.top() != ')') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } else if (isOperator(c)) {
            while (!operators.empty() && getPrecedence(operators.top()) > getPrecedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    std::reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    std::string infixExpression = "A + B * ( C - D ) / E";
    std::string prefixExpression = convertInfixToPrefix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Prefix Expression: " << prefixExpression << std::endl;

    return 0;
}