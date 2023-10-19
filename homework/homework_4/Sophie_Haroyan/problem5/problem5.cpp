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

    std::vector<std::string> text(size);
    std::string elem;

    for (int i = 0; i < size; ++i) {
        std::cin >> elem;
        text[i] = elem;
    }
    return text;

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
void binary(std::vector<bool>&, std::vector<std::vector<std::string>>&, std::vector<std::string>&, int);

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

void print(const std::vector<std::string>& subsets, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << "\n";
    }
    std::cout << std::endl;
    for (int i = 0; i < subsets.size(); ++i) {
        std::cout << subsets[i];
    }
}

void makeSet(std::vector<std::string>& stringSet) {
    std::vector<std::string> newString = stringSet;
    int strSize = stringSet.size();
    
    int i = 0;
    while (i < strSize) {
        std::string element = newString[i];
        
        int j = i + 1;
        while (j < strSize) {
            if (element == newString[j]) {
                newString.erase(newString.begin() + j);
                strSize = newString.size();
            } else {
                ++j;
            }
        }
        
        ++i;
    }

}


void binary(std::vector<bool>& binaryVector, std::vector<std::vector<std::string>>& subsets, const std::vector<std::string>& stringSet, int row) {
    bool check = true;
    int i = binaryVector.size() - 1;
    while (i >= 0) {
        if (binaryVector[i] == 0) {
            binaryVector[i] = 1;
            break;
        } else {
            if (i > 0) {
                binaryVector[i] = 0;
            }
        }
        i--;
    }

    i = 0;
    while (i < binaryVector.size()) {
        if (binaryVector[i] == 0) {
            check = false;
        }
        i++;
    }

    i = 0;
    while (i < binaryVector.size()) {
        if (binaryVector[i]) {
            subsets[row].push_back(stringSet[i]);
        }
        i++;
    }

    if (!check) {
        row++;
        binary(binaryVector, subsets, stringSet, row);
    } else {
        return;
    }


}

std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string> stringSet) {
    std::vector<bool> binaryVector(stringSet.size());
    int row = 0;
    std::vector<std::vector<std::string>> subsets(std::pow(2, stringSet.size()) -1);
    binary(binaryVector, subsets, stringSet,row);
    return subsets;
}
