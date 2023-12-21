#ifndef STARS_HPP
#define STARS_HPP

#include "GameObjects.hpp"

class Stars : public GameObjects
{
private:
    Direction dir;

public:
    Stars(Direction);
    ~Stars() {}

    void move(Direction, const Matrix &);
    char getSymbol() const;
};

#endif // STARS_HPP