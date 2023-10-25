#include <iostream>
#include <string>

bool containsDoubleA(const std::string& s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'a' && s[i + 1] == 'a') {
            return true;
        }
    }
    return false;
}

int main() {
    std::string s;
    std :: cout << "input string: ";
    while (std::getline(std::cin, s)) {
        if (s.back() == 'b' && !containsDoubleA(s)) {
            std::cout  << s << "  is acceptable: "<< std::endl;
        } else {
            std::cout << s << "  isn't acceptable: " << std::endl;
        }
    }

    return 0;
}
