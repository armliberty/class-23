#include <cassert>
#include <cmath> // std::isnan
#include <iostream>
#include <limits>
#include <sstream> // std::istringstream
#include <stack>

template <typename T>
T input(std::string_view msg);

template <>
std::string input(std::string_view msg) {
    std::cout << msg << ": ";
    std::string v;
    std::getline(std::cin, v);
    return v;
}

inline constexpr auto NaN = std::numeric_limits<double>::quiet_NaN();

bool isOperator(const std::string& token) {
    return token.size() == 1 && token.find_first_of("+-*/") != std::string::npos;
}

double invokeOp(const std::string& token, double arg1, double arg2) {
    assert(token.size() == 1);
    switch (token[0]) {
    case '+':
        return arg1 + arg2;
    case '-':
        return arg1 - arg2;
    case '*':
        return arg1 * arg2;
    case '/':
        return arg2 != 0 ? arg1 / arg2 : NaN;
    }
    return NaN;
}

double pop(std::stack<double>& stack) {
    if (stack.empty()) {
        return NaN;
    }
    auto arg = stack.top();
    stack.pop();
    return arg;
}

bool isValid(double d) {
    return !std::isnan(d);
}

double postfixEval(const std::string& expr) {
    std::istringstream istr(expr);
    std::stack<double> stack;
    std::string token;
    while (istr >> token) {
        if (isOperator(token)) {
            const auto arg2 = pop(stack);
            const auto arg1 = pop(stack);
            const auto res = invokeOp(token, arg1, arg2);
            if (!isValid(res)) {
                return res;
            }
            stack.push(res);
        } else {
            stack.push(std::stod(token));
        }
    }
    return stack.top();
}

double prefixEval(const std::string& expr) {
    std::stack<double> stack;
    for (int i = expr.length() - 1; i >= 0; --i) {
        if (expr[i] == ' ' || expr[i] == '\t') {
            continue; 
        } else if (isOperator(std::string(1, expr[i]))) {
            const auto arg1 = pop(stack);
            const auto arg2 = pop(stack);
            const auto res = invokeOp(std::string(1, expr[i]), arg1, arg2);
            if (!isValid(res)) {
                return res;
            }
            stack.push(res);
        } else {
            std::string operand;
            while (i >= 0 && !isOperator(std::string(1, expr[i])) &&
                   expr[i] != ' ' && expr[i] != '\t') {
                operand = expr[i] + operand;
                --i;
            }
            stack.push(std::stod(operand));
            ++i;
        }
    }
    return stack.top();
}

int main() {
    const auto postfixExpr = input<std::string>("Input postfix expression");
    const auto postfixResult = postfixEval(postfixExpr);
    if (isValid(postfixResult)) {
        std::cout << "Postfix Result: " << postfixResult << std::endl;
    } else {
        std::cout << "Error in Postfix Expression" << std::endl;
    }

    const auto prefixExpr = input<std::string>("Input prefix expression");
    const auto prefixResult = prefixEval(prefixExpr);
    if (isValid(prefixResult)) {
        std::cout << "Prefix Result: " << prefixResult << std::endl;
    } else {
        std::cout << "Error in Prefix Expression" << std::endl;
    }

    return 0;
}
