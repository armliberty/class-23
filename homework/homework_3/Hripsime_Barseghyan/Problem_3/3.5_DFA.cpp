#include <iostream>
#include <string>

std::string input(std::string msg);
bool isSymbol(char c);
bool isValidEmail(const std::string email);


int main() {
    const auto email = input("Input an E-mail");
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
    if (c == '_' | c == '.' | c == '-')
        return true;
    else 
    return false;
}


bool isValidEmail(const std::string email) {
    const auto stateCount = email.size();
    int state = 0;
    int index = 0;

    for (int i = 0; i < stateCount; i++) {
        char c = email[i];
        
        //First character
        if (i == 0) {
            if (isalpha(c)) {
                state++;
            } else {
                state = -1; // Transition to an invalid state
                return 0;
            }
        } 

        //Before @
        else if (index == 0) {
            if (isalpha(c) | isalnum(c) | isSymbol(c)) 
                state++;
            else if (c == '@') {
                state++;
                index++;
            } 
            else {
                state = -1; 
                return 0;
            }
        } 
        
        //After @, brefore .
        else if (index == 1) {
            if (isalpha(c) | c == '-') 
                state++;
            else if(email[i] == '.'){
                state++;
                index++; 
            }
            else {
                state = -1; 
                return 0;
            }
        } 
        
        //After .
        else if (index == 2) {
            if (isalpha(c)) {
                state++;
            } 
            else {
                state = -1; 
                return 0;
            }
        }
    }

    if(index == 2 && state != -1)
        return true;
    else 
        return false;
}