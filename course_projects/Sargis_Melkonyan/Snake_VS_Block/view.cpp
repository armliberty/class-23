#include "view.hpp"

int menuView(){
    auto menuwin = initWindow(30 ,60, 1, 10);
    box(menuwin, 0, 0);
    wrefresh(menuwin);
    keypad(menuwin, true);

    const char* choices[] = {
        "Play",
        "Settings",
        "Help",
        "Exit",
    };

    int choice;
    int highlight = 0;

    while (1) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight)
                wattron(menuwin, A_REVERSE); // Highlight the current choice
            mvwprintw(menuwin, i + 10, 25,"%s", choices[i]);
            wattroff(menuwin, A_REVERSE); // Turn off the highlight
        }

        choice = wgetch(menuwin); // Get user input

        switch (choice) {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 4)
                highlight = 3;
            break;
        default:
            break;
        }

        if(choice == 10) //key ENTER
            break;
    } 

    endwin();

    return highlight;
}


void gameView(Board gameBoard, Snake player, Block enemy, size_t delay_for_generation,
                WINDOW* playBoard, WINDOW* scoreBoard
                ){
    int x = 1;
    int y = 5;

    nodelay(stdscr, TRUE);   // for acynchron input

    werase(playBoard);
    werase(scoreBoard);

    box(playBoard, 0, 0);
    box(scoreBoard, 0, 0);

    keypad(playBoard, true);
    keypad(scoreBoard, true);


    for (y = 1; y < gameBoard.width - 6; y++)
        for (x = 1; x < gameBoard.length - 1; x++){
            playerView(player, gameBoard, x, y, playBoard);
            
            blocksView(gameBoard , &enemy, playBoard, x, y);

        }

    auto time = convertChar(delay_for_generation / 1000);
    mvwprintw(scoreBoard, 1, 1,"%s", "time:");
    mvwprintw(scoreBoard, 1, 7,"%s", time);

    auto playerLvl = convertChar(player.value);
    mvwprintw(scoreBoard, 2, 1, "%s", "lvl:");
    mvwprintw(scoreBoard, 2, 6, "%s", playerLvl);

    wrefresh(playBoard);
    wrefresh(scoreBoard);

    werase(playBoard);
    werase(scoreBoard);
}


const char* convertChar(size_t sizeTvalue){

    std::string sizeString = std::to_string(sizeTvalue);
    const char* timeOut = sizeString.c_str();

    return timeOut;
}


WINDOW* initWindow(int height, int width, int startyY, int startyX){
    initscr();
    noecho();
    curs_set(0);
    refresh();

    WINDOW *newWindow = newwin(height, width, startyY, startyX);

    return newWindow;
}


void playerView(Snake &player, Board &gameBoard, int x, int y, WINDOW *playBoard){
    if(gameBoard.gameMap[x][y] == player.symbol){
                mvwprintw(playBoard, y, x, "%s", "0");
                mvwprintw(playBoard, y+1, x, "%s","0");
                mvwprintw(playBoard, y+2, x, "%s","0");
                mvwprintw(playBoard, y+3, x, "%s","0");
            }
}


void blocksView(Board &gameBoard ,Block *blocksVector, WINDOW *playBoard, int x, int y){
    for(int i = 0; i < blocksVector->blocks.size(); ++i){
        if(gameBoard.gameMap[x][y] == blocksVector[i].symbol){
            mvwprintw(playBoard, y, x, "%s", "B");
        }
    }
}