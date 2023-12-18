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

bool isValid(double d);
double postfixEval(const std::string& expr);
double prefixEval(const std::string& expr);

int main() {
    const auto expr = input<std::string>("Input postfix expression");
    const auto result = postfixEval(expr);
    if (isValid(result)) {
        std::cout << "Result: " << result << std::endl; 
    } else {
        std::cout << "Error" << std::endl;
    }
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
    std::istringstream  istr(expr);
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

//std::string reverseByTokens(const std::string& s) {
//    const auto recersed = reverse(s);
//
//}

//double prefixEval(const std::string& expr) {
//    return postfixEval(reverseByTokens(expr));
// }
