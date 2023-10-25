#include <iostream>
#include <string>
#include <vector>

//alias
using StateId = int;
using StateIds = std::vector<StateId>;
using TrMatrix = std::vector<StateIds>;


std::string input(std::string);

int main(){
    const auto text = input("input the");
    const StateId alphabetsize = 2;
    TrMatrix EmptyMatrix = createEmptyMatrix(alphabetsize);

    return 0;
}

std::string input(const std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::cin >> value;
    return value;
}

TrMatrix createEmptyMatrix(StateId size){

}
