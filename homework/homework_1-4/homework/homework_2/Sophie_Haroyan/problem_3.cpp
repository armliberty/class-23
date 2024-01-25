#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>

/// TODO: npos

/// type alias
using StateId = int;
using StateIds = std::vector<StateId>;
/// TrMatrix : char x StateIds -> StateIDs
using TrMatrix = std::vector<StateIds>;

template <typename T>
T input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;

    return value;
}

template <>
std::string input(std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::getline(std::cin, value);

    return value;
}

template <typename T>
void print(T, std::string = "");

TrMatrix computeTransitionMatrix(const std::string& pattern);
std::vector<size_t> fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text);

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();
    const auto indexPositions = fsmFindFirstMatch(trFunc, finalState, text);
    if(indexPositions.size() > 0)
    {
        for (int i = 0; i < indexPositions.size(); i++)
        {
            print(indexPositions[i] - pattern.size() + 1, std::to_string(i + 1) + "th position");
        }
    }
    else {
        print("Pattern not found");
    }
}

template <typename T>
void print(T value, std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}

bool areSubstringEqual(const std::string& s, size_t sub1StartIndex, size_t sub1EndIndex, size_t sub2StartIndex, size_t sub2EndIndex)
{
    int result = s.compare(sub1StartIndex, sub1EndIndex + 1, s, sub2StartIndex, sub2EndIndex - sub2StartIndex + 1);
    return result == 0;
}

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if ((c == tolower(pattern[currStateId]) || c == toupper(pattern[currStateId])) && currStateId != finalState) {
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

TrMatrix computeTransitionMatrix(const std::string& pattern) {
    const auto stateCount = 1 + pattern.size();
    const auto alfabetSize = std::numeric_limits<char>::max();
    TrMatrix trFunc(stateCount, StateIds(alfabetSize));
    for (StateId stateId = 0; stateId < stateCount; ++stateId) {
        if (pattern[stateId] == '.' && stateId != stateCount - 1) {
            for(int i = 0; i < alfabetSize; ++i) {
                trFunc[stateId][i] = stateId + 1;
            }
        }
        else {
            for (char c = 0; c < alfabetSize; ++c) {
                trFunc[stateId][c] = computeNextState(stateId, c, pattern);
            }
        }
    }

    return trFunc;
}

std::vector<size_t> fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text) {
    std::vector<size_t> indexPositions;
    StateId currState = 0;
    
    for (size_t i = 0; i < text.size(); ++i) {
        currState = trMx[currState][text[i]];
        if (currState == finalState) {
            indexPositions.push_back(i);
            currState --;
        }
    }

    return indexPositions;
}