#include <cmath> // std::pow
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

template <typename T>
T input(const std::string &msg = "");
// template <>
// std::string input(const std::string& msg = "");
// template <>
// std::vector<std::string> input();
template <typename T>
void print(const T &, const std::string &msg = "");
void print(const std::vector<std::string> &, const std::string &msg = "");

void makeSet(std::vector<std::string> &);
std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string>);

std::vector<std::string> inputStringSet()
{
    auto strings = input<std::vector<std::string>>("Input strings");
    makeSet(strings);
    return strings;
}

int main()
{
    const auto size = input<size_t>("Input the string count");
    const auto stringSet = inputStringSet();
    print(std::pow(2, stringSet.size()) - 1, "Expected powerset cardinality");
    const auto subsets = computeSubsets(stringSet);
    print(subsets.size(), "Computed powerset cardinality");
    std::cout << "Computed powerset: ";
    for (const auto &s : subsets)
        print(s);
}

void makeSet(std::vector<std::string> &str)
{
    int i = 0;
    int j = 0;

    while (i < str.size())
    {
        j = i + 1;
        while (j < str.size())
        {
            if (str[i] == str[j])
                str.erase(str.begin() + j);
            else
                ++j;
        }
        ++i;
    }
}

std::vector<std::vector<std::string>> computeSubsets(const std::vector<std::string> text)
{
    int vec_size = pow(2, text.size());
    std::vector<std::vector<std::string>> vec(vec_size);
    size_t size = text.size();
    std::vector<std::vector<std::string>> output;

    for (size_t i = 0; i < vec_size; ++i)
    {
        std::string binary = std::bitset<64>(i).to_string().substr(64 - size);
        std::vector<std::string> inner = {binary};
        output.push_back(inner);
    }
        for(size_t i = 0; i < output.size(); ++i) {
            for(size_t k = 0; k < output[i][0].length(); ++k ) {
                if (output[i][0][k] == '1'){
                    std::cout << text[k];
                }
            }   
        std::cout << std::endl;
        }
    return output;
}