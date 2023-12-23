#include "game.hpp"

const std::chrono::milliseconds TACT{100};

void Game::gameLogic(Board &gBoard, Block &enemy ,Snake &player,Ball &ball, size_t delay){

    // std::this_thread::sleep_for(TACT);
    
    // int blockMaxValue = delay/10;

    int x, y;
    
    gBoard.clearBoard();

    // enemy.blockGenerator(delay);

    enemy.bloksPushDoun(enemy.blocks);

    snakeCoordination(gBoard, player, x, y);

    blocksCoordination(gBoard, enemy, x, y);
}


void Game::snakeCoordination(Board &gBoard, Snake &player, int x, int y){
    // if(x == player.headCoordX && y == player.headCoordY )
                gBoard.gameMap[player.headCoordX][player.headCoordY] = player.symbol;

}

void Game::blocksCoordination(Board &gameBoard ,Block &blocksVector, int x, int y){
    for(int i = 0; i < blocksVector.blocks.size(); ++i){
        gameBoard.gameMap[blocksVector.blocks[i].coordX][blocksVector.blocks[i].coordY] = blocksVector.symbol;
    }
}
