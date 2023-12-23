#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <chrono>
#include "game.hpp"
#include <iostream>
#include "view.hpp"

using TimePointer = std::chrono::_V2::steady_clock::time_point;

class Controller{
    public: 
        void run();
        size_t delayConvInt(TimePointer start_time_pointer,TimePointer curr_time_pointer);
        void isGameOver(bool &is_game_in_process, Snake &player);
        
};

#endif
