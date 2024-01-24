#include <cmath> // std::pow
#include <iostream>
#include <string>
#include <vector>

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
void makeSet(std::vector<std::string>&);
std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>);

std::vector<std::string> inputStringSet() {
   auto strings = input<std::vector<std::string>>("Input strings");
   makeSet(strings);
   return strings;
}
//added new methods
void getBinaries(std::vector<int>&,const std::vector<std::string>&,std::vector<std::vector<std::string>>&, int&);//get the binary list
void pushSubSet(std::vector<int>&, const std::vector<std::string>&, std::vector<std::vector<std::string>>&, int&); //one-by-one push each subset into set 

template <typename T>
void print(const T& value, const std::string& msg = "") { 
if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}
void print(const std::vector<std::string>&, const std::string& msg = "");


int main() {
    const auto stringSet = inputStringSet();
    print(std::pow(2, stringSet.size()) - 1, "Expected powerset cardinality");
    const auto subsets = computeSubsets(stringSet);
    print(subsets.size(), "Computed powerset cardinality");
    std::cout << "Computed powerset: ";
    for (const auto& s : subsets) {
       print(s);
    }
    std::cout << std::endl;
}
void print(const std::vector<std::string>& s, const std::string& msg) {
    if (msg != "") {
        std::cout << msg << "\n";
    }
    std::cout << std::endl;
    std::cout << "{";
    for (int i = 0; i < s.size(); ++i) {
        std::cout << s[i];
    }
    std::cout << "}";
}

std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string> stringSet) {
    int rows = pow(2, stringSet.size()) - 1;
    int colums = stringSet.size();
    std::vector<std::vector<std::string>> set(rows, std::vector<std::string>(colums));
    int startRow{0};
    std::vector<int> binary(stringSet.size());
    getBinaries(binary, stringSet, set, startRow);
    return set;
}

void getBinaries(std::vector<int>& binary, const std::vector<std::string>& stringSet, std::vector<std::vector<std::string>>& set, int& row) {
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (!binary[i]) {
            binary[i] = 1;
            break;
        } else {
            if (i) {
                binary[i] = 0;
            }
        }
    }
    bool check{true};
    for (int i = 0; i < binary.size(); ++i) {
        if (!binary[i]) {
            check = false;
        }
    }
    pushSubSet(binary, stringSet, set, row);
    if (check) {
        return;
    } else {
        ++row;
        getBinaries(binary, stringSet, set, row);
    }
}

void pushSubSet(std::vector<int>& binary,const  std::vector<std::string>& stringSet, std::vector<std::vector<std::string>>& set, int& row) {
    for(int i = 0; i < binary.size(); ++i) {
        if (binary[i]) {
            set[row][i] = stringSet[i];
        }
    }
}

void makeSet(std::vector<std::string>& stringSet) {
std::vector<std::string> set;
std::string elem;
bool check{true};

for (int i = 0; i < stringSet.size(); ++i) {
    elem = stringSet[i];
    for (int j = i + 1; j < stringSet.size(); ++j) {
        if (stringSet[j] == elem) {
            check = false;
            break;
        }
    }
    if (check) {
        set.push_back(elem);
    }
    check = true;
}
std::swap(stringSet, set);
}