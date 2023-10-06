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
T input(std::string msg, bool& check) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T value;
    std::cin >> value;
    if (msg == "Input search pattern") {
        for (int i = 0; i < value.size(); ++i) {
            if (value[i] == '?') {
                check = true;
            }
        }
    }

    return value;
}

template <>
std::string input(std::string msg, bool& check) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::string value;
    std::getline(std::cin, value);

    if (msg == "Input search pattern") {
        for (int i = 0; i < value.size(); ++i) {
            if (value[i] == '?') {
                check = true;
            }
        }
    }

    return value;
}

template <typename T>
void print(T, std::string = "");

TrMatrix computeTransitionMatrix(const std::string& pattern);
std::optional<size_t> fsmFindFirstMatch(const TrMatrix& trMx, StateId finalState, const std::string& text);
std::string getNewPattern(const std::string&, bool);

int main() {
    bool check{false};
    const auto pattern = input<std::string>("Input search pattern", check);
    const auto text = input<std::string>("Input text to search", check);
    if (check) {
        std::string newPattern1 = getNewPattern(pattern, check); //get string without ? and preceding character
        std::string newPattern2 = getNewPattern(pattern, false); //get string wthout ?
        //for pattern wtihout ? and preceding character
        const auto trFunc1 = computeTransitionMatrix(newPattern1);
        const auto finalStateOf1 = newPattern1.size();
        const auto optIndex1 = fsmFindFirstMatch(trFunc1, finalStateOf1, text);
        //for pattern without ?
        const auto trFunc2  = computeTransitionMatrix(newPattern2);
        const auto finalStateOf2 = newPattern2.size();
        const auto optIndex2 = fsmFindFirstMatch(trFunc2, finalStateOf2, text);
        if (optIndex1.has_value()) {
            print(optIndex1.value(), "Found at");
        }
        if (optIndex2.has_value()) {
            print(optIndex2.value(), "Found at");
        } 
        if (!(optIndex1.has_value() ||  optIndex2.has_value())) {
            std::cout << "Match not found" << "\n";
        }
        return 0;
    }

    const auto trFunc = computeTransitionMatrix(pattern);
    const auto finalState = pattern.size();
    const auto optIndex = fsmFindFirstMatch(trFunc, finalState, text);
    if (optIndex.has_value()) {
        print(optIndex.value(), "Found at");
        return 0;
    }
    std::cout << "Match not found" << "\n";
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

StateId computeNextState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
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

//Added methods
std::string getNewPattern(const std::string& pattern, bool check)
{
    if (!check) {
        std::string newString;
        char symbolToRemove = '?';
        for (char c : pattern) {
            if(c != symbolToRemove) {
                newString += c;
            }
        }
        return newString;
    }
    
    std::string newString;
    char symbolToRemove1 = '?';
    char symbolToRemove2;

    for (int i = 0; i < pattern.size(); ++i) {
        if (pattern[i] == '?') {
            symbolToRemove2 = pattern[i - 1];
        }
    }

    for (char c : pattern) {
        if(c != symbolToRemove1 &&  c != symbolToRemove2) {
            newString += c;
        }
    }
    return newString;
}

