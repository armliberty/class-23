
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
    const auto stringSet = inputStringSet();
    print(std::pow(2, stringSet.size()) - 1, "Expected powerset cardinality");
    const auto subsets = computeSubsets(stringSet);
    print(subsets.size(), "Computed powerset cardinality");
    std::cout << "Computed powerset: " << std::endl;
    for (const auto& s : subsets) {
        print(s);
    }
}
 


template <typename T>
void print(const T &value, const std::string& msg) {
    if (!msg.empty()) 
        std::cout << msg << ": ";
    
    std::cout << value << std::endl;
}


void print(const std::vector<std::string>& str, const std::string& msg) {
    if (!msg.empty()) 
        std::cout << msg << ": ";
    
    std::cout << "{";
    
    for (int i = 0; i < str.size(); i++)
        std::cout << str[i];
    
    std::cout << "}" << std::endl;
}

template <typename T>
T input(const std::string& msg) {
    if (!msg.empty()) 
        std::cout << msg << ": ";
    
    T value;
    std::cin >> value;
    return value;
}

template <>
std::string input(const std::string& msg) {
    if (!msg.empty()) 
        std::cout << msg << ": ";
    
    std::string value;
    std::getline(std::cin, value);
    return value;
}

template <>
std::vector<std::string> input(const std::string& msg) {
    const auto size = input<size_t>("Input the string count");
    if (!msg.empty()) 
        std::cout << msg << ": ";

    std::vector<std::string> str(size);
    std::string input;

    for (int i = 0; i < size; ++i) {
        std::cin >> input;
        str[i] = input;
    }
    return str;
}


void makeSet(std::vector<std::string>& strings) {
    std::vector<std::string> uniqueStrings;
    
    for (int i = 0; i < strings.size(); i++) {
        bool isDuplicate = false;
        
        for (int j = 0; j < i; j++) 
            if (strings[i] == strings[j]) {
                isDuplicate = true;
                break;  
            }
        
        if (!isDuplicate) 
            uniqueStrings.push_back(strings[i]);
        
    }
    strings = uniqueStrings;  
}


std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string> strings) {
    std::vector<std::vector<std::string>> Subsets;
    int numSubsets = std::pow(2, strings.size());

    for (size_t i = 1; i < numSubsets; i++) { 
        std::vector<std::string> subset;
        for (size_t j = 0; j < strings.size(); j++) 
            if (i & (1 << j)){
                subset.push_back(strings[j]);
            }        
        Subsets.push_back(subset);
    }

    return Subsets;
}