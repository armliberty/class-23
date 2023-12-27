#ifndef CHECKERS_HPP
#define CHECKERS_HPP

#include <string>

class Board
{
public:
    Board(int color);
    int GetCellColor() const;
    void SetCellColor(int color);
    bool IsQueen() const;
    void SetQueen(bool isQueen);
    std::string GetType() const;

private:
    int cellColor;
    bool queen;
    bool isPromoted;
};

#endif // CHECKERS_HPP