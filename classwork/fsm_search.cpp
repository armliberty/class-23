#include <iostream>
#include <limits>
#include <string>
#include <vector>

/// type alias
using Row = std::vector<int>;
using TrMatrix = std::vector<Row>;

const auto ALFABET_SIZE = std::numeric_limits<char>::max();

template <typename T>
T input(std::string msg);
template <typename T>
void print(T, std::string);

TrMatrix computeTransitionMatrix(std::string pattern);
std::string::size_type search(TrMatrix, std::string);

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTransitionMatrix(pattern);
    const auto index = search(trFunc, text);
    print(index, "Found at");

}

template <typename T>
T input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;
}

template <>
std::string input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::getline(std::cin, value);
}

template <typename T>
void print(T value, std::string msg) {
    if (msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;;
}

TrMatrix computeTransitionMatrix(std::string pattern) {
    TrMatrix trFunc(pattern.size() + 1, Row(ALFABET_SIZE));
}

std::string::size_type search(TrMatrix, std::string) {

}
