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
std::optional<size_t> fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text);

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();
    const auto optIndex = fsmFindFirstMatch(trFunc, finalState, text);
    if (optIndex.has_value()) {
        print(optIndex.value(), "Found at");
    } else {
        print("Pattern not found");
    }
}

template <typename T>
void print(T value, std::string msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;;
}

bool areSubstringEqual(const std::string& s, size_t sub1StartIndex, size_t sub1EndIndex, size_t sub2StartIndex) {
    return s.compare(sub1StartIndex, sub1EndIndex + 1, s, sub2StartIndex);
}

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if (c == pattern[currStateId] && currStateId != finalState) {
        return currStateId + 1;
    }
    for (StateId nextState = currStateId; nextState > 0; --nextState) {
        const auto nextStateLastChar = pattern[nextState - 1];
        if (c != nextStateLastChar) {
            continue;
        }
        const auto prefixStartIndex = 0;
        const auto prefixEndIndex = nextState - 1;
        const auto suffixEndIndex = currStateId;
        const auto suffixStartIndex =  currStateId - (prefixEndIndex);
        if (areSubstringEqual(pattern, prefixStartIndex, prefixEndIndex, suffixStartIndex)) {
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

std::optional<size_t> fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text) {
    StateId currState = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        currState = trMx[currState][text[i]];
        if (currState == finalState) {
            return i;
        }
    }
    return std::nullopt;
}
