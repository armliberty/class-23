#include "prefix.hpp"

int getOperatorPrecedence(char op)
{
    switch (op)
    {
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

void handleParenthesis(char c, std::stack<char>& _stack_, std::string &res)
{
    if (c == '(')
        _stack_.push('(');
    else if (c == ')')
    {
        while (_stack_.top() != '(')
        {
            res += _stack_.top();
            _stack_.pop();
        }
        _stack_.pop();
    }
}

std::string infixToPostfix(std::string infix)
{
    infix = '(' + infix + ')';
    int len = infix.size();
    std::stack<char> _stack_;
    std::string postfixResult;

    for (int i = 0; i < len; i++)
    {
        if (isalnum(infix[i]))
            postfixResult += infix[i];
        else if (infix[i] == '(' || infix[i] == ')')
            handleParenthesis(infix[i], _stack_, postfixResult);
        else
        {
            while (!_stack_.empty() && getOperatorPrecedence(infix[i]) <= getOperatorPrecedence(_stack_.top()))
            {
                postfixResult += _stack_.top();
                _stack_.pop();
            }
            _stack_.push(infix[i]);
        }
    }
    while (!_stack_.empty())
    {
        postfixResult += _stack_.top();
        _stack_.pop();
    }
    return postfixResult;
}

std::string reverseExpression(const std::string &expr)
{
    std::string reversedExpr = expr;

    std::reverse(reversedExpr.begin(), reversedExpr.end());
    for (char &c : reversedExpr)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    return (reversedExpr);
}

std::string convertInfixToPrefix(const std::string &infix)
{
    std::string reversedInfix = reverseExpression(infix);
    std::string toPostfix = infixToPostfix(reversedInfix);
    std::string rversePostfixtoPrefix = reverseExpression(toPostfix);

    //debugging segfault
    // return (rversePostfixtoPrefix);
    // return (reversedInfix);
    return (toPostfix);
}
