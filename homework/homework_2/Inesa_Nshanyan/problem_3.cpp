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
int dot_index(const std::string&);
TrMatrix computeTransitionMatrix(const std::string& pattern, int dotIndex);
std::vector<size_t> fsmFindAllMatches(const TrMatrix& trMx, StateId finalState, const std::string& text);

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const int dotIndex = dot_index(pattern);
    const auto trFunc = computeTransitionMatrix(pattern, dotIndex);
    const auto finalState = pattern.size();
    std::vector<size_t> allmatches = fsmFindAllMatches(trFunc, finalState, text);
    if (allmatches.empty()) {
        print("Pattern not found");
    }
    else {
        for (size_t i = 0; i < allmatches.size(); ++i) {
            std::cout << "First symbol position: " << allmatches[i] << " \n";
            std::cout << "Last symbol position: " << (allmatches[i] + pattern.size() - 1) << " \n";
        }
    }
}
int dot_index(const std::string& pattern) {
    for (auto i = 0; i < pattern.size(); i++)
    {
        if (pattern[i] == '.')
        {
            return i;
        }
    }
    return 0;
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

StateId computeNextState(StateId currStateId, char c, const std::string& pattern, int dotIndex) {
    const auto finalState = pattern.size();
    if (currStateId == dotIndex)
    {
        return currStateId + 1;
    }
    if (c == pattern[currStateId] && currStateId != finalState) {
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

    return StateId{ 0 };
}

TrMatrix computeTransitionMatrix(const std::string& pattern, int dotIndex) {
    const auto stateCount = 1 + pattern.size();
    const auto alfabetSize = std::numeric_limits<char>::max();
    TrMatrix trFunc(stateCount, StateIds(alfabetSize));
    for (StateId stateId = 0; stateId < stateCount; ++stateId) {
        for (char c = 0; c < alfabetSize; ++c) {
            trFunc[stateId][c] = computeNextState(stateId, c, pattern, dotIndex);
        }

    }

    return trFunc;
}

std::vector<size_t> fsmFindAllMatches(const TrMatrix& trMx, StateId finalState, const std::string& text) {
    StateId currState = 0;
    std::vector<size_t> allmatches;

    for (size_t i = 0; i < text.size(); ++i) {
        currState = trMx[currState][text[i]];
        if (currState == finalState) {
            allmatches.push_back(i);
        }
    }
    return allmatches;
}