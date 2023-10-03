#include "fsm_general.cpp"

std::vector<int> fsmFindMatch(const TrMatrix& trMx, StateId finalState, const std::string& text);


int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();
    std::vector<int> optIndex = fsmFindMatch(trFunc, finalState, text);
    std::cout <<  std::endl;
    
    for (int i = 0; i < optIndex.size(); i++)
    {
        if(i == 0) std::cout << "Position counting starts from 0." << std::endl;
        std::cout << "Match number " << i + 1<< " :" << std::endl;
        if (!optIndex.empty()) {
            print(optIndex[i] - pattern.size() + 1, "    First symbol position");
            print(optIndex[i], "    Last symbol position");
        } 
        else 
            print("Pattern not found");
    }
}


std::vector<int> fsmFindMatch(const TrMatrix& trMx, StateId finalState, const std::string& text) {
    StateId currState = 0;
    std::vector<int> x; 
    for (size_t i = 0; i < text.size(); ++i) {
        currState = trMx[currState][text[i]];
        if (currState == finalState) 
            x.push_back(i);
    }

    return x;
}
