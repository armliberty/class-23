#include <iostream>
#include <stack>
#include <cctype>


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
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string convertInfixToPrefix(const std::string& infixStr) {
    std::stack<char> st;
    std::string result;

    for (int i = infixStr.length() - 1; i >= 0; --i) {
        char currentChar = infixStr[i];

        if (isalnum(currentChar)) {
            result = currentChar + result; // Build operands directly
        } else if (currentChar == ')') {
            st.push(currentChar);
        } else if (currentChar == '(') {
            while (!st.empty() && st.top() != ')') {
                result = st.top() + result;
                st.pop();
            }
            st.pop(); // Pop ')'
        } else if (isOperator(currentChar)) {
            while (!st.empty() && getPrecedence(st.top()) > getPrecedence(currentChar)) {
                result = st.top() + result;
                st.pop();
            }
            st.push(currentChar);
        }
    }

    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    int intValue = input<int>("Enter an integer");
    double doubleValue = input<double>("Enter a double");
    std::string stringValue = input<std::string>("Enter a string");

    std::cout << "You entered: " << intValue << ", " << doubleValue << ", " << stringValue << std::endl;

    return 0;
}