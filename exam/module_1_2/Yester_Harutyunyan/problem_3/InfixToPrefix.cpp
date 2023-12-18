#include <stack>
#include <algorithm>
#include <string>
#include <iostream>



template <typename T>
T input(std::string_view msg);

template <>
std::string input(std::string_view msg) {
    std::cout << msg << ": ";
    std::string v;
    std::getline(std::cin, v);
    return v;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string convertInfixToPrefix(const std::string& infixStr) {
    std::stack<char> operatorStack;
    std::string prefixExpression;

    for (auto i = infixStr.size() - 1; i != std::string::npos; --i) {
        if (std::isalnum(infixStr[i]) || infixStr[i] == '.') {
            prefixExpression += infixStr[i];
        } else if (isOperator(infixStr[i])) {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) > getPrecedence(infixStr[i])) {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(infixStr[i]);
        } else if (infixStr[i] == '(') {
            while (!operatorStack.empty() && operatorStack.top() != ')') {
                prefixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        } else if (infixStr[i] == ')') {
            operatorStack.push(infixStr[i]);
        }
    }

    while (!operatorStack.empty()) {
        prefixExpression += operatorStack.top();
        operatorStack.pop();
    }

    std::reverse(prefixExpression.begin(), prefixExpression.end());

    return prefixExpression;
}

int main() {
    const auto infixExpression = input<std::string>("Input infix expression");
    const std::string prefixExpression = convertInfixToPrefix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Prefix Expression: " << prefixExpression << std::endl;

    return 0;
}
