#ifndef DFA_HPP
#define DFA_HPP

#include <optional>
#include <vector>
#include <string>

//ALIASES
using StateId = int;
using StateIds = std::vector<StateId>;
using TrMatrix = std::vector<StateIds>;


class DFA {
    public:
        DFA(const std::string&);
        bool validate();
    private:
        void createMatrix(); //empty matrix
        void fillMatrix(); //start to get transitions
        StateId computeNextState(char, StateId);
    private:
    TrMatrix m_trMatrix;
    std::string m_input;
    int m_states{4};
};

#endif
