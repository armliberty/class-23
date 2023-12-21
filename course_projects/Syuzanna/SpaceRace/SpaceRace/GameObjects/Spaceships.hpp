#ifndef SPACESHIPS_HPP
#define SPACESHIPS_HPP

#include "GameObjects.hpp"

class Spaceships : public GameObjects
{

public:
    Spaceships() {}
    ~Spaceships() {}

public:
    void move(Direction, const Matrix &);
    char getSymbol() const;
};

#endif // SPACESHIPS_HPP