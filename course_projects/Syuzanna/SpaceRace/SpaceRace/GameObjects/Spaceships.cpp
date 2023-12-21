#include "Spaceships.hpp"

void Spaceships::move(Direction dir, const Matrix &matrix)
{

    switch (dir)
    {
    case Direction::Up:
        if (x - 1 < 0)
            x = (int)matrix.size() - 1;
        else
            --x;
        break;
    case Direction::Down:
        if (x + 1 < (int)matrix.size())
            ++x;
        break;
    default:
        break;
    }
}

char Spaceships::getSymbol() const
{
    return 'S';
}