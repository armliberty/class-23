#include <iostream>
#include <limits>
#include <optional>
#include <string>
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

TrMatrix computeTransitionMatrix(const std::string& pattern);
size_t fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text);

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();
    const auto index = fsmFindFirstMatch(trFunc, finalState, text);
    print(index == std::string::npos ? "Pattern not found."  : "Found at index: " + std::to_string(index));
}

template <typename T>
void print(T value, const std::string& msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}

bool areSubstringsEqual(const std::string& s, size_t sub1StartIndex, size_t sub1EndIndex,
                                                size_t sub2StartIndex, size_t sub2EndIndex) {
    return 0 == s.compare(sub1StartIndex, sub1EndIndex - sub1StartIndex + 1, s, sub2StartIndex, sub2EndIndex - sub2StartIndex + 1);
}

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if (c == pattern[currStateId] && currStateId != finalState) {
        return currStateId + 1;
    }
    for (auto nextState = currStateId; nextState > 0; --nextState) {
        const auto prefixEndIndex = nextState - 1;
        const auto suffixStartIndex = currStateId - prefixEndIndex;
        const auto suffixEndIndex = currStateId - 1;
        if (c == pattern[prefixEndIndex] &&
                (prefixEndIndex == 0 || areSubstringsEqual(pattern, 0, prefixEndIndex - 1, suffixStartIndex, suffixEndIndex))) {
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
        for (char c = 0; c < alfabetSize; ++c) {
            trFunc[stateId][c] = computeNextState(stateId, c, pattern);
        }
    }
    return trFunc;
}

size_t fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text) {
    StateId currState = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        currState = trMx[currState][text[i]];
        if (currState == finalState) {
            return i - finalState + 1;
        }
    }
    return std::string::npos;
}