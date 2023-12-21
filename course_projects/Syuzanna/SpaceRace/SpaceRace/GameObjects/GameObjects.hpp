#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <vector>

enum Direction
{
    Left,
    Right,
    Up,
    Down,
    None
};

class GameObjects
{
    
protected:
    int x;
    int y;
    using Matrix = std::vector<std::vector<char>>;

public:
    GameObjects() {}
    virtual ~GameObjects() {}
    
    virtual void move(Direction, const Matrix &) = 0;
    virtual char getSymbol() const = 0;
    int getx() const { return x; }
    int gety() const { return y; }
    void setxy(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setx(int x) { this->x = x; }
};

#endif // GAME_OBJECT_HPP