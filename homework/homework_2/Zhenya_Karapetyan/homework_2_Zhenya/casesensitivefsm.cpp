#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>
#include <cctype>

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
    std::cin.ignore();
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
    int result = s.compare(sub1StartIndex, sub1EndIndex + 1, s, sub2StartIndex, sub2EndIndex - sub2StartIndex + 1);
    return result == 0;
}

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if (tolower(c) == tolower(pattern[currStateId]) && currStateId != finalState) {
        return currStateId + 1;
    }

    auto s = pattern;
    s[currStateId] = tolower(c);

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

std::vector<size_t> fsmFindAllMatches(const TrMatrix& trMx, StateId finalState, const std::string& text) {
    StateId currState = 0;
    std::vector<size_t> matchIndices;

    for (size_t i = 0; i < text.size(); ++i) {
        currState = trMx[currState][tolower(text[i])];
        if (currState == finalState) {
            matchIndices.push_back(i - pattern.size() + 1);
        }
    }

    return matchIndices;
}

int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();
    const auto matchIndices = fsmFindAllMatches(trFunc, finalState, text);

    if (!matchIndices.empty()) {
        std::cout << "Pattern found at positions: ";
        for (size_t i = 0; i < matchIndices.size(); ++i) {
            if (i > 0) {
                std::cout << ", ";
            }
            std::cout << matchIndices[i];
        }
        std::cout << std::endl;
    } else {
        print("Pattern not found");
    }

    return 0;
}
