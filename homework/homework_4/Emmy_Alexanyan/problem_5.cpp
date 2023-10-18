#include <cmath> // std::pow

#include <iostream>

#include <string>

#include <vector>



template <typename T>

T input(const std::string& msg = "") {

    if (!msg.empty()) {

        std::cout << msg << ":" << std::endl;

    }

    T value;

    std::cin >> value;

    return value;

}



template <>

std::string input(const std::string& msg) {

    if (!msg.empty()) {

        std::cout << msg << ":" << std::endl;

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



    std::vector<std::string> vector(size);

    std::string el_vec;



    for (int i = 0; i < size; ++i) {

        std::cin >> el_vec;

        vector[i] = el_vec;

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

void Binary_rows(std::vector<bool>&, std::vector<std::vector<std::string>>&, std::vector<std::string>&, int);



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

    std::string el_string;

    string = stringSet;

    stringSet.clear();

    bool check = true;

    for (int i = 0; i < string.size(); ++i) {

        el_string = string[i];

        for (int j = i + 1; j < string.size(); ++j) {

            if (el_string == string[j]) {

                check = false;

            }



        }

        if (check) {

            stringSet.push_back(el_string);

        }

        check = true;

    }

}



void Binary_rows(std::vector<bool>& binary_row, std::vector<std::vector<std::string>>& subsets, const std::vector<std::string>& stringSet, int row_subset) {

    bool check = true;

        for (int i = binary_row.size() - 1; i >= 0; --i) {

            if (binary_row[i] == 0) {

                binary_row[i] = 1;

                break;

            }

            else {

                if (i) {

                    binary_row[i] = 0;

                }

            }

        }



        for (int i = 0; i < binary_row.size(); ++i) {

            if (binary_row[i] == 0) {

               check = false;

            }

        }

        for (int i = 0; i < binary_row.size(); ++i) {

            if (binary_row[i]) {

                subsets[row_subset].push_back(stringSet[i]);

            }

        }

            if (!check) {

                row_subset++;

                Binary_rows(binary_row, subsets, stringSet, row_subset);

            }

            else {

                return;

            }



}



std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string> stringSet) {

    std::vector<bool> binary_row(stringSet.size());

    int row_subset = 0;

    std::vector<std::vector<std::string>> subsets(std::pow(2, stringSet.size()) -1);

    Binary_rows(binary_row, subsets, stringSet,row_subset);

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
