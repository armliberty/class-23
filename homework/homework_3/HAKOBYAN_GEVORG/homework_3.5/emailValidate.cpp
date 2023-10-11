#include "DFA.hpp"
#include <iostream>
#include <string>

std::string inputEmail();
void validate(const std::string&);

int main() {
    std::string email = inputEmail();
    validate(email);
    return 0;
}

std::string inputEmail() {
    std::string email;
    std::cout << "Input email address to validate: ";
    std::cin >> email;
    return email;
}

void validate(const std::string& email) {
    DFA validator(email);
    if (validator.validate()) {
        std::cout << "The email - " << email << ": is valid" << "\n";
    } else {
        std::cout << "The email - " << email << ": isn't valid" << "\n";
    }
}
