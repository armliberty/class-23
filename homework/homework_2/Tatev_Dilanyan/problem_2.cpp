#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>
#include <algorithm> // For std::transform

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
    std::cin.ignore(); // Ignore any leftover newline characters
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
bool areSubstringEqual(const std::string& s, size_t sub1StartIndex, size_t sub1EndIndex, size_t sub2StartIndex, size_t sub2EndIndex);


StateId computeNextState(StateId currStateId, char c, const std::string& pattern);

TrMatrix computeTransitionMatrix(const std::string& pattern);

std::vector<int> fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text);

int main() {
    std::string pattern = input<std::string>("Input search pattern");
    std::string text = input<std::string>("Input text to search");

    // Convert both pattern and text to lowercase
    std::transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();

    std::vector<int> optIndex = fsmFindFirstMatch(trFunc, finalState, text);
    if (!optIndex.empty()) {
        for (StateId i = 0; i < optIndex.size(); i++) {
            print(optIndex[i], "First symbol position");
            print(optIndex[i] + pattern.size() - 1, "Last symbol position");
        }
    } else {
        print("Pattern not found");
    }
    return 0;
}


bool areSubstringEqual(const std::string& s, size_t sub1StartIndex, size_t sub1EndIndex, size_t sub2StartIndex, size_t sub2EndIndex)
{
    for (size_t i = sub1StartIndex, j = sub2StartIndex; i <= sub1EndIndex && j <= sub2EndIndex; ++i, ++j) {
        if (std::tolower(s[i]) != std::tolower(s[j])) {
            return false;
        }
    }
    return true;
}

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    char lowerC = std::tolower(c); // Convert character to lowercase

    if (lowerC == std::tolower(pattern[currStateId]) && currStateId != finalState) {
        return currStateId + 1;
    }

    auto s = pattern;
    s[currStateId] = std::tolower(lowerC); // Store the lowercase character in the pattern

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

std::vector<int> fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text) {
    std::vector<int> allOccurrences;
    StateId currState = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        char lowerTextChar = std::tolower(text[i]); // Convert text character to lowercase
        currState = trMx[currState][lowerTextChar];
        if (currState == finalState) {
            allOccurrences.push_back(i - finalState + 1);
        }
    }
    return allOccurrences;
}

