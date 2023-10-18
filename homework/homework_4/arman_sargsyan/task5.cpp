#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>

void makeSet(std::vector<std::string>&);
std::vector<std::vector<std::string>>  computeSubsets(std::vector<std::string>);

int main()
{
    std::vector<std::string> text = {"a","b","c","a"};
    makeSet(text);
    computeSubsets(text);
    return 0;
}

void makeSet(std::vector<std::string>& text){
    int i = 0, j = 0;
    while ( i < text.size() ) {
        while ( j < text.size() ){
            if ( j != i && text[i] == text[j] ){
                text.erase( text.begin() + j );
            } else {
                ++j;
            }
        }
        ++i;
        j = 0;
    }
};

std::vector<std::vector<std::string>>  computeSubsets(std::vector<std::string> text){
    std::cout << text.size() << std::endl;
    const long unsigned size = text.size();
    std::vector<std::vector<std::string>> output; 
    for (size_t i = 0; i < pow( 2, text.size() ); ++i) {
        std::string binary = std::bitset<64>(i).to_string().substr(64 - size);
        std::vector<std::string> inner = { binary };
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