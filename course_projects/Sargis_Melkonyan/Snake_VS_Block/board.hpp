#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <array>
#include <string>
// #include <vector>
#include "block.hpp"
#include "ball.hpp"

class Board{
    public:    
        static const std::size_t width = 35;
        static const std::size_t length = 50;
        
        std::array<std::array<char, 35UL>, 50UL> gameMap;
        // Board();
        void clearBoard();
        // std::vector<Block> blocks;
        // std::vector<Ball> balls;

};

#endif
