#include <iostream>
#include <string>

bool isLineValid(const std::string& line) {
    if (line.find("aa") != std::string::npos) {
        return false;
    }

    return line.back() == 'b';
}

int main() {
    std::cout << "Enter text lines:\n";

    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }

        if (isLineValid(line)) {
            std::cout << "Valid: " << line << std::endl;
        } else {
            std::cout << "Invalid: " << line << std::endl;
        }
    }

    return 0;
}
