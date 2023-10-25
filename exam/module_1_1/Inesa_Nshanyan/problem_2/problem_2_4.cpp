//Inesa_Nshanyan_119_U
#include <iostream>
#include <string>

bool isValid(const std::string&);

int main() {
    std::string text;
    std::cin >> text;
    if (isValid(text)) {
        std::cout << "text is valid";
    }
    else {
        std::cout << "text is not valid";
    }
}

bool isValid(const std::string& text) {
    auto size = text.size();
    int i = 0;
    if (text[size - 1] != 'b') {
        return false;
    }
    while (i < size - 1) {
        if (text[i] == 'a' && text[i + 1] == 'a') {
            return false;
        }
        i++;
    }
    return true;
}