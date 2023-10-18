#include <cmath> // std::pow
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T input(const std::string& msg = "");
template <>
std::string input(const std::string& msg);
template <>
std::vector<std::string> input(const std::string& msg);

template <typename T>
void print(const T&, const std::string& msg = "");
void print(const std::vector<std::string>&, const std::string& msg = "");

void makeSet(std::vector<std::string>&);
std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>);

std::vector<std::string> inputStringSet() {
    auto strings = input<std::vector<std::string>>("Input strings");
    makeSet(strings);
    return strings;
}

int main() {
    const auto size = input<size_t>("Input the string count");
    const auto stringSet = inputStringSet();
    print(std::pow(2, stringSet.size()) - 1, "Expected powerset cardinality");
    const auto subsets = computeSubsets(stringSet);
    print(subsets.size(), "Computed powerset cardinality");
    std::cout << "Computed powerset: ";
    for (const auto& s : subsets) {
        print(s);
    }
}
 
/*
 * Here comes your code
 */



template <typename T>
void print(const T &value, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}

template <typename T>
void print(const std::vector<T>& v, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << "[ ";
    for (const auto& e : v) {
        std::cout << e << "; ";
    }
    std::cout << "]" << std::endl;
}

template <typename T>
T input(const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;
    return value;
}

template <>
std::string input(const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::getline(std::cin, value);
    return value;
}