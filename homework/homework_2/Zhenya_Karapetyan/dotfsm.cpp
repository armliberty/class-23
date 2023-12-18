#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>

using StateId = int;
using StateIds = std::vector<StateId>;
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
void print(T value, std::string msg = "") {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << value << std::endl;
}

bool areSubstringEqual(const std::string& s, size_t sub1StartIndex, size_t sub1EndIndex, size_t sub2StartIndex, size_t sub2EndIndex) {
    int result = s.compare(sub1StartIndex, sub1EndIndex - sub1StartIndex + 1, s, sub2StartIndex, sub2EndIndex - sub2StartIndex + 1);
    return result == 0;
}

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if (c == '.' || c == pattern[currStateId]) {
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
    const auto alphabetSize = std::numeric_limits<char>::max();
    TrMatrix trFunc(stateCount, StateIds(alphabetSize));
    for (StateId stateId = 0; stateId < stateCount; ++stateId) {
        for (char c = 0; c < alphabetSize; ++c) {
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
            return i - finalState + 1;
        }
    }

    return std::nullopt;
}

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();
    size_t currentIndex = 0;

    while (true) {
        const auto optIndex = fsmFindFirstMatch(trFunc, finalState, text.substr(currentIndex));
        if (optIndex.has_value()) {
            currentIndex += optIndex.value() + 1;
            print(currentIndex - pattern.size(), "Pattern found at position");
        } else {
            break;
        }
    }

    return 0;
}