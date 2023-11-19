#include "fsm_general.cpp"

TrMatrix computeTranMatrix(const std::string& pattern);
StateId computeNxtState(StateId currStateId, char c, const std::string& pattern);


int main() {
    const auto pattern = input<std::string>("Input search pattern");
    const auto text = input<std::string>("Input text to search");
    const auto trFunc = computeTranMatrix(pattern);
    const auto finalState = pattern.size();
    const auto optIndex = fsmFindFirstMatch(trFunc, finalState, text);
    if (optIndex.has_value()) {
        print(optIndex.value() - pattern.size() + 1, "First symbol position");
        print(optIndex.value(), "Last symbol position");
    } 
    else {
        print("Pattern not found");
    }
}

StateId computeNxtState(StateId currStateId, char c, const std::string& pattern) {
    const auto finalState = pattern.size();
    if ((c == pattern[currStateId] || pattern[currStateId] == '.') && currStateId != finalState) {
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
            if (pattern[stateId] == '.' || pattern[stateId] == c)
            {
                trFunc[stateId][c] = stateId + 1;
            }
            else
                trFunc[stateId][c] = computeNxtState(stateId, c, pattern);
        }
    }

    return trFunc;
}
