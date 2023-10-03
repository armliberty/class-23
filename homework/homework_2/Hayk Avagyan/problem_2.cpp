#include "fsm_general.cpp"

StateId computeNxtState(StateId currStateId, char c, const std::string& pattern);
TrMatrix computeTranMatrix(const std::string& pattern);
std::vector<int> fsmFindMatch(const TrMatrix& trMx, StateId finalState, const std::string& text);


int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTranMatrix(pattern);
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


StateId computeNxtState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if ((tolower(c) == tolower(pattern[currStateId]) || tolower(c) == toupper(pattern[currStateId])  
        || toupper(c) == tolower(pattern[currStateId]) || toupper(c) == toupper(pattern[currStateId]) ) && currStateId != finalState) {
        return currStateId + 1;
    }

    auto s = pattern;
    s[currStateId] = c;

    for (StateId nextState = currStateId; nextState > 0; --nextState) {
        const auto prefixStartIndex = 0;
        const auto prefixEndIndex = nextState - 1;
        const auto suffixEndIndex = currStateId;
        const auto suffixStartIndex = currStateId - (prefixEndIndex);

        if (areSubstringEqual(s, prefixStartIndex, prefixEndIndex, suffixStartIndex, suffixEndIndex)) {
            return nextState;
        }
    }

    return StateId{0};
}


TrMatrix computeTranMatrix(const std::string& pattern) {
    const auto stateCount = 1 + pattern.size();
    const auto alfabetSize = std::numeric_limits<char>::max();
    TrMatrix trFunc(stateCount, StateIds(alfabetSize));
    for (StateId stateId = 0; stateId < stateCount; ++stateId) {
        for (char c = 0; c < alfabetSize; ++c) {
            trFunc[stateId][c] = computeNxtState(stateId, c, pattern);
        }
    }

    return trFunc;
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