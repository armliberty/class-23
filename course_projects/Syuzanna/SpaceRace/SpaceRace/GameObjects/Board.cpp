#include "Board.hpp"
#include "Spaceships.hpp"
#include "Stars.hpp"

#include <stdlib.h>

Board::Board(Player player1, Player player2) : player1(player1), player2(player2)
{
    startTime = time(0);
    PlayerSpaceShip1 = new Spaceships();
    PlayerSpaceShip1->setxy(height - 1, width / 4);
    PlayerSpaceShip2 = new Spaceships();
    PlayerSpaceShip2->setxy(height - 1, width - (width / 4));
    addToMap(PlayerSpaceShip1);
    addToMap(PlayerSpaceShip2);
    srand(time(0));
    Direction dir;
    for (int i = height - 3; i > 0; i -= 2)
    {
        if (rand() % 2 == 0)
            dir = Direction::Right;
        else
            dir = Direction::Left;
        auto star = new Stars(dir);
        star->setxy(i, rand() % (int)(width - 1));
        stars.push_back(star);
    }
}

Board::~Board()
{
    delete PlayerSpaceShip1;
    delete PlayerSpaceShip2;
    for (auto &star : stars)
        delete star;
    stars.clear();
}

Player Board::getPlayer1Score() const
{
    return score1;
}

Player Board::getPlayer2Score() const
{
    return score2;
}

void Board ::movePlayer1(Direction dir)
{
    int score1=getPlayer1().getScore();
    removeFromMap(PlayerSpaceShip1);
    PlayerSpaceShip1->move(dir, map);
    if (PlayerSpaceShip1->getx() == 0)
    {
        ++score1;
        player1.setScore(score1);
        addToMap(PlayerSpaceShip1);
    }
    addToMap(PlayerSpaceShip1);
}

void Board ::movePlayer2(Direction dir)
{
    int score2=getPlayer2().getScore();
    removeFromMap(PlayerSpaceShip2);
    PlayerSpaceShip2->move(dir, map);
    if (PlayerSpaceShip2->getx() == 0)
    {
        ++score2;
        player2.setScore(score2);
        addToMap(PlayerSpaceShip2);
    }
    addToMap(PlayerSpaceShip2);
}

void Board ::removeFromMap(GameObjects *obj)
{
    const int x = obj->getx();
    const int y = obj->gety();
    map[x][y] = ' ';
}

void Board ::addToMap(GameObjects *obj)
{
    const int x = obj->getx();
    const int y = obj->gety();
    map[x][y] = obj->getSymbol();
}

Board::Matrix Board::getMatrix() const
{
    return map;
}

void Board::update()
{
    for (int i = 0; i < (int)stars.size(); ++i)
    {
        removeFromMap(stars[i]);
        stars[i]->move(Direction::None, map);
        int x = stars[i]->getx();
        int y = stars[i]->gety();
        if (map[x][y] == 'S')
        {
            if (y <= width / 2)
            {
                removeFromMap(PlayerSpaceShip1);
                PlayerSpaceShip1->setx(height - 1);
                addToMap(PlayerSpaceShip1);
            }

            else
            {
                removeFromMap(PlayerSpaceShip2);
                PlayerSpaceShip2->setx(height - 1);
                addToMap(PlayerSpaceShip2);
            }
        }
        addToMap(stars[i]);
    }
}

Player Board::getPlayer1() const
{
    return player1;
}

Player Board::getPlayer2() const
{
    return player2;
}
