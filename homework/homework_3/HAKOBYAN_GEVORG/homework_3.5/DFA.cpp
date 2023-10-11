#include "DFA.hpp"
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>

bool isAlphanumeric(char);
bool isAt(char);
bool isPunctuation(char);
bool isDot(char);

DFA::DFA(const std::string& email) {
    m_input = email;
    createMatrix();
}

void DFA::createMatrix() {
    StateId alphabetSize = std::numeric_limits<char>::max();
    m_trMatrix = TrMatrix(m_states, StateIds(alphabetSize));
}

void DFA::fillMatrix() {
    StateId alphabetSize = std::numeric_limits<char>::max();
    for (StateId currState = 0; currState < m_states; ++currState) {
        for (char c = 0; c < alphabetSize; ++c) {
           m_trMatrix[currState][c] = computeNextState(c, currState);
        }
    }
}

StateId DFA::computeNextState(char c, StateId currState) {
    int nextState = currState + 1;
    switch(currState) {
        case 2:
        case 0: {
            if (isAlphanumeric(c)) {
                return nextState;
            } else {
                return currState;
            }
            break;
        }
        case 1: {
            if (isAt(c)) {                  //@
                return nextState + 2;
            } else if(isPunctuation(c)) { //- _ .
                return nextState;
            } else {
                return currState;
            }
            break;
        }
        case 3: {
            if (isAt(c)) {                  //@
                return nextState;
            } else {
                return currState;
            }
            break;
        }
        case 4: {
            if (isDot(c)) {
                return nextState;
            } else {
                return currState;
            }
        }
        case 5: {
            if (99 == c) { // c
                return nextState;
            } else {
                return currState;
            }
            break;
        }
        case 6: {
            if (111 == c) { // 0
                return nextState;
            } else {
                return currState;
            }
            break;
        }
        case 7: {
            if (109 == c) { // c
                return nextState;
            } else {
                return currState;
            }
            break;
        }
    }
    return 0;
}

bool DFA::validate() {
    fillMatrix();
    StateId currState = 0;
    for (size_t i = 0; i < m_input.size(); ++i) {
        currState = m_trMatrix[currState][m_input[i]];
    }
    if (currState == m_states) {
        return true;
    } 
    return false;
}

bool isAlphanumeric(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) { //[a-z] [A-Z] [0-9]
        return true;
    } else {
        return false;
    }
}

bool isAt(char c) {
    if (64 == c) {                  //@
        return true;
    } else {
        return false;
    }
}

bool isPunctuation(char c) {
    if (45 == c || 46 == c || 95 == c) {
        return true;
    } else {
        return false;
    }
}

bool isDot(char c) {
    if (46 == c) {
        return true;
    } else {
       return false;
    }
}
