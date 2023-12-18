#include <iostream>
#include <stack>
#include <string>
#include <cctype>

bool isOperator(char ch) {
    return (ch == '+'||  ch == '-'||  ch == '*'||  ch == '/' ||  ch == '^');
}

int invokeOp(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' ||  op == '/')
        return 2;
    else if (op == '+' ||  op == '-')
        return 1;
    else
        return 0;
}

bool isHigherPrecedence(char op1, char op2) {
    int prec1 = invokeOp(op1);
    int prec2 = invokeOp(op2);
    return prec1 > prec2 || (prec1 == prec2 && (op1 != '^' || op2 != '^'));
}

std::string convertInfixToPrefix(const std::string& infixStr) {
    std::stack<char> operators;
    std::stack<std::string> operands;

    for (char ch : infixStr) {
        if (std::isspace(ch))
            continue;

        if (std::isalnum(ch)) {
            operands.push(std::string(1, ch));
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                std::string op2 = operands.top();
                operands.pop();

                std::string op1 = operands.top();
                operands.pop();

                operands.push(std::string(1, operators.top()) + op1 + op2);
                operators.pop();
            }
            operators.pop();
        } else if (ch == '(') {
            operators.push(ch);
        } else if (isOperator(ch)) {
            while (!operators.empty() && isHigherPrecedence(operators.top(), ch)) {
                std::string op2 = operands.top();
                operands.pop();

                std::string op1 = operands.top();
                operands.pop();

                operands.push(std::string(1, operators.top()) + op1 + op2);
                operators.pop();
            }
            operators.push(ch);
        }
    }
    while (!operators.empty()) {
        std::string op2 = operands.top();
        operands.pop();

        std::string op1 = operands.top();
        operands.pop();

        operands.push(std::string(1, operators.top()) + op1 + op2);
        operators.pop();
    }

    return operands.top();
}

int main() {
    std::cout << "Enter an infix expression: ";
    std::string infixExpr;
    std::getline(std::cin, infixExpr);

    const std::string prefixExpr = convertInfixToPrefix(infixExpr);

    std::cout << "Infix Expression: " << infixExpr << std::endl;
    std::cout << "Prefix Expression: " << prefixExpr << std::endl;

    return 0;
}
