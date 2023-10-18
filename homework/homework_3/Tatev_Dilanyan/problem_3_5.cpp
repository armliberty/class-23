#include <iostream>
#include <string>

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_valid(const std::string& email)
{
    if (!isChar(email[0])) {
        return false;
    }

    int At = -1, Dot = -1;
    int countAt = 0, countDot = 0;

    for (size_t i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            countAt++;
            At = i;
        }
        else if (email[i] == '.') {
            countDot++;
            Dot = i;
        }
    }
    if (At == -1 || Dot == -1) {
        return false;
    }
    if (At > Dot) {
        return false;
    }
    if (Dot >= static_cast<int>(email.length() - 1)) {
        return false;
    }
    if (countAt > 1 || countDot > 1) {
        return false;
    }
    if (At + 1 == Dot || Dot + 1 == At) {
        return false;
    }

    return true;
}

std::string input(const std::string& prompt)
{
    std::string userInput;
    std::cout << prompt;
    std::cin >> userInput;
    return userInput;
}

int main()
{
    std::string email = input("Enter an email address: ");

    bool ans = is_valid(email);
    if (ans) {
        std::cout << email << " : " << "valid" << std::endl;
    }
    else {
        std::cout << email << " : " << "invalid" << std::endl;
    }

    return 0;
}
