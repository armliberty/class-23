#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>
#include <ncurses.h>
#include "game.hpp"
#include <string>

int menuView();
void gameView(Board, Snake, Block, size_t, WINDOW*, WINDOW*);
WINDOW* initWindow(int, int, int, int);
const char* convertChar(size_t sizeTvalue);
void playerView(Snake &player, Board &gameBoard, int x, int y, WINDOW *playBoard);
void blocksView(Board &gameBoard ,Block *blocksVector, WINDOW *playBoard, int x, int y);
// void initializeCurses();

#endif