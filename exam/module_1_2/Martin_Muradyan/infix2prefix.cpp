#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

template <typename T>
T input(std::string_view msg);

template <>
std::string input(std::string_view msg) {
    std::cout << msg << ": ";
    std::string v;
    std::getline(std::cin, v);
    return v;
}

std::string convertInfixToPrefix(const std::string& infix);

int main() {
    
    std::cout << "Enter an infix expression: ";
    const auto infixExpression = input<std::string>("Input postfix expression");
    std::string postfixExpression = convertInfixToPrefix(infixExpression);

    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

std::string convertInfixToPrefix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix;

    for (char token : infix) {
        if (isalnum(token)) {
            postfix += token;
        } 
        else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    std::reverse(postfix.begin(), postfix.end());

    return postfix;
}


