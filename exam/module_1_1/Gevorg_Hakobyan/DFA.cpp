#include "DFA.hpp"
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <vector>

bool isA_Z(char);
bool isB_Z(char);
bool isB(char);
bool isA(char);

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
        case 0: {
            if (isA_Z(c) && !isB(c)) {
                return nextState;
            } else if (isB(c)){
                return m_states;
            }
            break;
        }
        case 1: {
            if (isA(c)) {                  
                return 0;
            } else if (isB(c)){
                return m_states;
            } else {
                return nextState;
            }
            break;
        }
        case 2: {
            if (isB(c)) {                 
                return m_states;
            } else if (isA(c)){
                return 0;
            } else {
                return currState;
            break;
            }
        }
        case 3: {
            if (isB(c)) {
                return m_states;
            } else if (isA(c)){
                return 0;
            } else {
                return currState;
            break;
        }
       }
    }
    return 0;
}

bool DFA::validate() {
    fillMatrix();
    StateId currState = 0;
    for (size_t i = 0; i < m_input.size(); ++i) {
        currState = m_trMatrix[currState][m_input[i]];
        if (0 == currState) {
            return false;
            break;
        }
    }
    if (currState == m_states) {
        std::cout << currState << "\n";
        return true;
    }     
    std::cout << currState << "\n";
    return false;
}

bool isA_Z(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) { //[a-z] [A-Z] [0-9]
        return true;
    } else {
        return false;
    }
}

bool isB_Z(char c) {
    if ((c >= 66 && c <= 90) || (c >= 98 && c <= 122) || (c >= 48 && c <= 57)) { //[a-z] [A-Z] [0-9]
        return true;
    } else {
        return false;
    }
}

bool isB(char c){
    if (66 == c || 98 == c) {
        return true;
    }else {
        return false;
    }
}

bool isA(char c){
    if (65 == c || 97 == c) {
        return true;
    }else {
        return false;
    }
}

