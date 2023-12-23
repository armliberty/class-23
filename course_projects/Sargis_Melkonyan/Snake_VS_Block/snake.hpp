#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <ncurses.h>

class Snake{
    public:
        int value;
        int headCoordX;
        int headCoordY;
        char symbol;
    
    public:
        Snake();
        void snakeMove(WINDOW *playBoard);
        void valueDecrement();
        void valueIncrement();
};

#endif
