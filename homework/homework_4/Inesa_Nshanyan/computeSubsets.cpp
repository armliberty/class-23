#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T input(const std::string& msg);
template <>
std::string input(const std::string& msg);
template <>
std::vector<std::string> input(const std::string& msg);

template <typename T>
void print(T value, const std::string& msg);
void print(const std::vector<std::string>& vector, const std::string& msg);

void binary(int num, std::vector<std::vector<std::string>>& Subsets, int i);

void makeSet(std::vector<std::string>& vec);
std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>& vec);

std::vector<std::string> inputStringSet() {
    auto strings = input<std::vector<std::string>>("Input strings");
    makeSet(strings);
    return strings;
}

auto SIZE = 0;

int main() {
    SIZE = input<size_t>("Input the string count");
    const auto stringSet = inputStringSet();
    print(std::pow(2, stringSet.size()) - 1, "Expected powerset cardinality");
    const auto subsets = computeSubsets(stringSet);
    print(subsets.size(), "Computed powerset cardinality");
    std::cout << "Computed powerset: \n";
    for (const auto& s : subsets) {
        print(s, "");
    }
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

template <>
std::vector<std::string> input(const std::string& msg) {
    std::vector<std::string> vec;
    for (size_t i = 0; i <= SIZE; ++i) {
        std::string element = input<std::string>("Enter an element:");
        vec.push_back(element);
    }
    print(vec, "");
    return vec;
}

template <typename T>
void print(T value, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}

void print(const std::vector<std::string>& vector, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    for (const auto& element : vector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void makeSet(std::vector<std::string>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        size_t j = i + 1;
        while (j < vec.size()) {
            if (vec[i] == vec[j]) {
                vec.erase(vec.begin() + j);
            }
            else {
                ++j;
            }
        }
    }
    print(vec, "Unique elements");
}

void binary(int num, std::vector<std::vector<std::string>>& Subsets, int i) {
    for (size_t j = 0; j < Subsets[0].size(); ++j) {
        int binary = num % 2;
        Subsets[i][j] = std::to_string(binary);
        num /= 2;
    }
}


std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>& vec) {
    int rows = std::pow(2, vec.size() - 1);
    int columns = vec.size() - 1;
    std::vector<std::vector<std::string>> Subsets(rows, std::vector<std::string>(columns));
    for (int i = 0; i < rows; ++i) {
        binary(i, Subsets, i);
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (Subsets[i][j] == "1") {
                Subsets[i][j] = vec[j + 1];
            }
            else {
                Subsets[i][j] = "_";
            }
        }
    }
    return Subsets;
}