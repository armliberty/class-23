#include "snake.hpp"


Snake::Snake(){
    value = 4;
    headCoordX = 25;
    headCoordY = 25;
    symbol = 's';
}

void Snake::snakeMove(WINDOW *playBoard){

    nodelay(playBoard, TRUE);
    keypad(stdscr, true);
    int button ;
    button = getch();
    
    switch (button){
    case KEY_LEFT:{
        if(headCoordX > 1)
            headCoordX--;    
        }
        break;
    case KEY_RIGHT:{
        if(headCoordX < 48)
            headCoordX++;
        }
    default:
        break;
    }
}

void Snake::valueDecrement(){
    if(value >= 0){
        value--;
    }
}

void Snake::valueIncrement(){
    value++;
}