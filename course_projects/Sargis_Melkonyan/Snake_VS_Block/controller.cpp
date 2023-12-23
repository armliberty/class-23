#include "controller.hpp"


// using TimePointer = std::chrono::_V2::steady_clock::time_point;


void Controller::run(){
    Board gameBoard;
    Snake player;
    Game game;
    Block enemy;
    Ball ball;

    
    bool is_game_in_process = true;
    auto start_time = std::chrono::steady_clock::now();
    
    auto playBoard = initWindow(30, 50, 1, 10);
    auto scoreBoard = initWindow(30, 20, 1, 60);

    do{
        auto curr_time = std::chrono::steady_clock::now();

        size_t delay_for_generation = delayConvInt(start_time, curr_time);

        game.gameLogic(gameBoard, enemy, player, ball, delay_for_generation);

        gameView(gameBoard, player, enemy, delay_for_generation, playBoard, scoreBoard);
        
        player.snakeMove(playBoard);
        
        isGameOver(is_game_in_process, player);

    }while(is_game_in_process);

}


void Controller::isGameOver(bool &is_game_in_process, Snake &player){
    if(player.value == 0){
        is_game_in_process = true;
    }
}


size_t Controller::delayConvInt(TimePointer start_time_pointer,TimePointer curr_time_pointer){
    auto delay_by_miliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(curr_time_pointer - start_time_pointer );
    size_t out = static_cast<size_t>(delay_by_miliseconds.count());
    
    return out;
}

