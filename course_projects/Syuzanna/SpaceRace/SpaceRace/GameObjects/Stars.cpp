#include "Stars.hpp"

#include <time.h>
#include <stdlib.h>

Stars::Stars(Direction dir) : dir(dir)
{
}

void Stars::move(Direction, const Matrix &matrix)
{
    switch (dir)
    {
    case Direction::Right:
        if (y + 1 >= (int)matrix[0].size())
            y = 0;
        else
            ++y;
        break;
    case Direction::Left:
        if (y - 1 <= 0)
            y = matrix[0].size() - 1;
        else
            --y;
        break;
    default:
        break;
    }
}

char Stars::getSymbol() const
{
    return '_';
}