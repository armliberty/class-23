#include <iostream>
#include <stack>
#include <string>

template <typename T>
T input(std::string_view msg);

template <>
std::string input(std::string_view msg) {
    std::cout << msg << ": ";
    std::string v;
    std::getline(std::cin, v);
    return v;
}

std::string reverseString(const std::string& str);

std::string convertInfixToPrefix(const std::string& infix);

int main() {
    std::cout << "Enter an infix expression: ";
    const auto infixExpression = input<std::string>("Input infix expression");
    std::string prefixExpression = convertInfixToPrefix(infixExpression);

    std::cout << "Prefix expression: " << prefixExpression << std::endl;

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

std::string reverseString(const std::string& str) {
    std::string reversed;
    for (int i = str.size() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

std::string convertInfixToPrefix(const std::string& infix) {
    std::stack<char> operators;
    std::string prefix;

    for (auto it = infix.rbegin(); it != infix.rend(); ++it) {
        char token = *it;

        if (isalnum(token)) {
            prefix += token;
        } else if (token == ')') {
            operators.push(token);
        } else if (token == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) > getPrecedence(token)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    prefix = reverseString(prefix);

    return prefix;
}
