#ifndef GAME_HPP
#define GAME_HPP

#include "ball.hpp"
#include "block.hpp"
#include "board.hpp"
#include <chrono>
// #include "controller.hpp"
#include <iostream>
#include <ncurses.h>
#include "snake.hpp"
#include <thread>
#include <vector>
// #include "view.hpp"


class Game{
    public:
        // void startGame();
        // Game();
        void gameLogic(Board &gBoard,Block &blocksVector ,Snake &player,Ball &ball, size_t delay);
        void snakeCoordination(Board &gBoard, Snake &player, int x, int y);
        void blocksCoordination(Board &gameBoard ,Block &blocksVector,  int x, int y);
        // const char* Game::convertChar(size_t sizeTvalue);
        // void gameView(Board);
       
        // WINDOW *playBoard;
        // WINDOW *scoreBoard;
    
    private:
        const std::chrono::milliseconds gameTact{500};
};

#endif
