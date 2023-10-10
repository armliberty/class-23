#include <iostream>
#include <limits>
#include <string>
#include <tuple> // std::tie
#include <vector>

/// type alias
using StateId = int;
using StateIds = std::vector<StateId>;
/// TrMatrix : char x StateIds -> StateIDs
using TrMatrix = std::vector<StateIds>;

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

template <typename T>
void print(T, const std::string& msg = "");
template <typename T>
void print(const std::vector<T>& v, const std::string& msg = "");

std::vector<size_t> findAllMatches(const std::string& pattern, const std::string& text);
void markFoundIndices(size_t startOffset, const std::vector<size_t>&);

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const std::string inputTxtMsg = "Input text to search";
    const auto text = input<std::string>(inputTxtMsg);
    const auto matchedIndices = findAllMatches(pattern, text);
    markFoundIndices(inputTxtMsg.size() + 2, matchedIndices);
    print(matchedIndices, "Matched index list");
}

void markFoundIndices(size_t startOffset, const std::vector<size_t>& list){
    size_t lastElement = list[list.size() - 1];
    size_t i,j,n;
    // size_t newList = 
    for(n = 0; n < startOffset; n++){std::cout<<" ";}
    
    for(i = 0; i < list.size(); i++){
        for(j = 0; j < startOffset + lastElement + 1; j++){
            if(j == list[i]){
                std::cout<<"^";
                break;
            }
            else{
                std::cout<<" ";
            }
        }
    }
    
    std::cout<<std::endl;
}


template <typename T>
void print(T value, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}

template <typename T>
void print(const std::vector<T>& v, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << "[ ";
    for (const auto& e : v) {
        std::cout << e << "; ";
    }
    std::cout << "]" << std::endl;
}


bool areSubstringEqual(const std::string& s, size_t sub1StartIndex, size_t sub1EndIndex, size_t sub2StartIndex) {
    return 0 == s.compare(sub1StartIndex, sub1EndIndex + 1, s, sub2StartIndex);
}

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if (c == pattern[currStateId] && currStateId != finalState) {
        return currStateId + 1;
    }
    for (StateId nextState = currStateId; nextState > 0; --nextState) {
        const auto prefixStartIndex = 0;
        const auto prefixEndIndex = nextState - 1;
        const auto suffixEndIndex = currStateId;
        const auto suffixStartIndex = currStateId - (prefixEndIndex - prefixStartIndex);
        if (areSubstringEqual(pattern, prefixStartIndex, prefixEndIndex, suffixStartIndex)) {
            return nextState;
        }
    }
    return StateId{0};
}

std::pair<TrMatrix, StateId> computeTransitionMatrix(const std::string& pattern) {
    const auto stateCount = 1 + pattern.size();
    const auto alfabetSize = std::numeric_limits<char>::max();
    TrMatrix trFunc(stateCount, StateIds(alfabetSize));
    for (StateId stateId = 0; stateId < stateCount; ++stateId) {
        for (char c = 0; c < alfabetSize; ++c) {
            trFunc[stateId][c] = computeNextState(stateId, c, pattern);
        }
    }
    return {trFunc, pattern.size()};
}

std::pair<size_t, StateId> fsmCompute(const TrMatrix& trMx, StateId currState, StateId finalState,
                                    const std::string& text, size_t startIdx) {
    for (size_t i = startIdx; i < text.size(); ++i) {
        currState = trMx[currState][text[i]];
        if (currState == finalState) {
            return {i - finalState + 1, currState};
        }
    }
    return {std::string::npos, currState};
}

std::vector<size_t> findAllMatches(const std::string& pattern, const std::string& text) {
    const auto [trMx, finalState] = computeTransitionMatrix(pattern);
    std::vector<size_t> indices;
    auto [index, currState] = fsmCompute(trMx, StateId{0}, finalState, text, 0);
    while (index != std::string::npos) {
        if (currState == finalState) {
            indices.push_back(index);
        }
        std::tie(index, currState) = fsmCompute(trMx, currState, finalState, text, index + 1);
    }
    return indices;
}
