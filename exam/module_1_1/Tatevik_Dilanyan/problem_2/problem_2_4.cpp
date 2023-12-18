#include <iostream>
#include <string>

bool language(const std::string& txt);

int main() {
    std::string txt;
    std::cout << "Enter a string:: ";
    std::cin >> txt;

    if (matchesLanguage(txt)) {
        std::cout << "The input matches the specified language." << std::endl;
    } else {
        std::cout << "The input does not match the specified language." << std::endl;
    }

    return 0;
}

bool language(const std::string& txt) {
    if (txt.empty() || txt.back() != 'b') {
        return false;
    }
    for (size_t i = 0; i < text.length() - 1; ++i) {
        if (txt[i] == 'a' && txt[i + 1] == 'a') {
            return false;
        }
    }

    return true;
}
