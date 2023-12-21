#ifndef BOARD_HPP
#define BOARD_HPP

#include "GameObjects.hpp"
#include "../Player/Player.hpp"
#include <time.h>
#include <string>



class Board
{
private:
    Player score1; 
    Player score2;
    Player player1;
    Player player2;
    int height = 40;
    int width = 50;

    using Matrix = std::vector<std::vector<char>>;
    Matrix map = Matrix(height, std::vector<char>(width, ' '));
    GameObjects *PlayerSpaceShip1;
    GameObjects *PlayerSpaceShip2;
    std::vector<GameObjects *> stars;

public:
    Board(Player player1, Player player2);
    ~Board();

    time_t startTime;
    Player getPlayer1Score() const;
    Player getPlayer2Score() const;
    Player getPlayer1() const;
    Player getPlayer2() const;

    void update();
    void movePlayer1(Direction);
    void movePlayer2(Direction);

    void removeFromMap(GameObjects *);
    void addToMap(GameObjects *);
    Matrix getMatrix() const;
};

#endif // BOARD_HPP