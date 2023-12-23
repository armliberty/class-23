#include "board.hpp"


// Board::Board() {
//     std::array<std::array<char , width>, length> gameMap;

//     for(int x = 0; x < length; ++x)
//         for(int y = 0; y < width; ++y)
//             gameMap[x][y] = ' ';

// }


void Board::clearBoard(){
     for(int x = 0; x < length; ++x)
        for(int y = 0; y < width; ++y)
            gameMap[x][y] = ' ';
}