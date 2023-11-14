#include <array>
#include <iostream>
#include <limits>
#include <string_view>
#include <string>

template <typename T>
T input(std::string_view msg = "");
template <typename T>
void printLn(const T& v, std::string_view msg = "");

class FSM {
public:
    using Alphabet = unsigned char;

    FSM();
    void compute(const std::string&);
    bool isAccepted();
    void reset();

private:
    void initWithDeadState();
    void constructTransitions();

private:
    using State = size_t;
    static constexpr auto ALPHABET_MIN = std::numeric_limits<Alphabet>::min();
    static constexpr auto ALPHABET_MAX = std::numeric_limits<Alphabet>::max();
    static constexpr auto ALPHABET_SIZE = ALPHABET_MAX - ALPHABET_MIN + 1; 
    static constexpr auto STATE_COUNT = 4;
    static constexpr auto START_STATE = State{0};
    static constexpr auto DEAD_STATE = State{STATE_COUNT - 1};
    static constexpr auto FINAL_STATE = State{DEAD_STATE - 1};

    using StateRow = std::array<State, STATE_COUNT>;
    using TrMatrix = std::array<StateRow, ALPHABET_SIZE>;

    TrMatrix trMx_;
    State currState_ = START_STATE;
};

int main() {
    FSM fsm;
    const auto str = input<std::string>("Input string");
    fsm.compute(str);
    printLn(fsm.isAccepted(), "String accepted");
}

template <typename T>
T input(std::string_view msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    T v;
    std::cin >> v;
    return v;
}

template <typename T>
void printLn(const T& v, std::string_view msg) {
    if (!msg.empty()) {
        std::cout << msg << ": ";
    }
    std::cout << std::boolalpha << v << std::endl;
}

FSM::FSM() {
    initWithDeadState();
    constructTransitions();
}

void FSM::initWithDeadState() {
    StateRow deadRow;
    deadRow.fill(DEAD_STATE);
    trMx_.fill(deadRow);
}

void FSM::constructTransitions() {
    trMx_['a'][State{0}] = State{1};
    trMx_['b'][State{0}] = State{2};
    trMx_['b'][State{1}] = State{2};
    trMx_['a'][State{2}] = State{1};
    trMx_['b'][State{2}] = State{2};
}

void FSM::compute(const std::string& s) {
    for (auto c : s) {
        currState_ = trMx_[c][currState_];
    }
}

bool FSM::isAccepted() {
    return currState_ == FINAL_STATE;
}

void FSM::reset() {
    currState_ = START_STATE;
}
