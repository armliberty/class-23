#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

template <typename T>
T input(const std::string& msg);

template <>
std::string input(const std::string& msg) {
    std::cout << msg << ": ";
    std::string v;
    std::getline(std::cin, v);
    return v;
}

std::string prefixExpr(std::string expr);

int main() {
    const auto expr = input<std::string>("Input infix expression");
    const auto result = prefixExpr(expr);
    std::cout << result << std::endl;
}

std::string prefixExpr(std::string expr) {
    std::stack<char> operators;
    std::string prefix;
    auto index = 0;
    int length = expr.size();
    bool isOp = true;
    std::reverse(expr.begin(), expr.end());
    for (char current : expr) {
        if (isdigit(current) != 0) {
            prefix += current;
            ++index;
            if (!isOp) {
                prefix += operators.top();
                operators.pop();
                isOp = true;
            }
        }
        else if (current == '+' || current == '-') {
            operators.push(current);
        }
        else if (current == '*' || current == '/') {
            operators.push(current);
            isOp = false;
        }
    }
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }
    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}
