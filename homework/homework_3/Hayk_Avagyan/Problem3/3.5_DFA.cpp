#include <iostream>
#include <string>

std::string input(std::string msg);
bool isSymbol(char c);
bool isValidEmail(const std::string email);

int main() {
    const std::string email = input("Input an E-mail");
    if (isValidEmail(email)) 
        std::cout << "Email is valid.\n";
    else 
        std::cout << "Email is not valid.\n";
    
    return 0;
}

std::string input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::getline(std::cin, value);
    return value;
}

bool isSymbol(char c) {
    return (c == '_' || c == '.' || c == '-');
}

bool isValidEmail(const std::string email) {
    const int stateCount = email.size();
    int state = 0;
    int atIndex = -1;  
    int dotIndex = -1; 

    for (int i = 0; i < stateCount; i++) {
        char c = email[i];
        
        if (i == 0) {
            if (isalpha(c)) {
                state++;
            } else {
                return false;
            }
        } else if (atIndex == -1) {
            if (isalpha(c) || isdigit(c) || isSymbol(c)) {
                state++;
            } else if (c == '@') {
                state++;
                atIndex = i;
            } else {
                return false;
            }
        } else if (dotIndex == -1) {
            if (isalpha(c) || c == '-') {
                state++;
            } else if (c == '.') {
                state++;
                dotIndex = i;
            } else {
                return false;
            }
        } else {
            if (isalpha(c)) {
                state++;
            } else {
                return false;
            }
        }
    }

    if (state < 4 || atIndex == -1 || dotIndex == -1 || dotIndex <= atIndex + 1) {
        return false;
    }

    return true;
}