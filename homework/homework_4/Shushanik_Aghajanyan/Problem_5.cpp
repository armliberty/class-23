#include <cmath> // std::pow
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T input(const std::string& msg = "") {
    if (!msg.empty()) {
        std::cout << msg << ":" << std::endl;
    }
    T val;
    std::cin >> val;
    return val;
}

template <>
std::string input(const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ":" << std::endl;
    }
    
    std::string val;
    std::getline(std::cin, val);
    return val;
}

template <>
std::vector<std::string> input(const std::string& msg) {
    const auto size = input<size_t>("Input the string count");
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }

    std::vector<std::string> vector(size);
    std::string element;

    for (int i = 0; i < size; ++i) {
        std::cin >> element;
        vector[i] = element;
    }
    return vector;

}
template <typename T>
void print(const T& value, const std::string& msg = "") {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}
void print(const std::vector<std::string>&, const std::string& msg = "");

void makeSet(std::vector<std::string>&);
std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>);
void makeBinary(std::vector<bool>&, std::vector<std::vector<std::string>>&, std::vector<std::string>&, int);

    std::vector<std::string> inputStringSet() {
    auto strings = input<std::vector<std::string>>("Input strings");
    makeSet(strings);
    return strings;
}

int main() {
    const auto stringSet = inputStringSet();
    print(std::pow(2, stringSet.size()) - 1, "Expected powerset cardinality");
    const auto subsets = computeSubsets(stringSet);
    print(subsets.size(), "Computed powerset cardinality");
    std::cout << "Computed powerset: ";
    for (const auto& s : subsets) {
        print(s);
    }

    return 0;
}

void makeSet(std::vector<std::string>& stringSet) {
    std::vector<std::string> string;
    std::string element;
    string = stringSet;
    stringSet.clear();
    bool check = true;
    for (int i = 0; i < string.size(); ++i) {
        element = string[i];
        for (int j = i + 1; j < string.size(); ++j) {
            if (element == string[j]) {
                check = false;
            }

        }
        if (check) {
            stringSet.push_back(element);
        }
        check = true;
    }
}

void makeBinary(std::vector<bool>& binary, std::vector<std::vector<std::string>>& subsets, const std::vector<std::string>& stringSet, int r) {
    bool check = true;
        for (int i = binary.size() - 1; i >= 0; --i) {
            if (binary[i] == 0) {
                binary[i] = 1;
                break;
            }
            else {
                if (i) {
                    binary[i] = 0;
                }
            }
        }

        for (int i = 0; i < binary.size(); ++i) {
            if (binary[i] == 0) {
               check = false;
            }
        }
        for (int i = 0; i < binary.size(); ++i) {
            if (binary[i]) {
                subsets[r].push_back(stringSet[i]);
            }
        }
            if (!check) {
                r++;
                makeBinary(binary, subsets, stringSet, r);
            }
            else {
                return;
            }

}

std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string> stringSet) {
    std::vector<bool> binary(stringSet.size());
    int r = 0;
    std::vector<std::vector<std::string>> subsets(std::pow(2, stringSet.size()) -1);
    makeBinary(binary, subsets, stringSet,r);
    return subsets;
}

void print(const std::vector<std::string>& subsets, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << "\n";
    }
    std::cout << std::endl;
    std::cout << "{";
    for (int i = 0; i < subsets.size(); ++i) {
        std::cout << subsets[i];
    }
    std::cout << "}" << std::endl;
}