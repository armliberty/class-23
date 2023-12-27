#ifndef PIECE_HPP
#define PIECE_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "const.hpp"


class Piece {

public:
    Piece(CellColor col = Empty, bool queen = false) : color(col), isQueen(queen) {}
    CellColor GetCellColor() const;
    void SetCellColor(CellColor col);
    bool IsQueen() const;
    void SetQueen(bool queen);
    std::string GetType() const;

    private:
    CellColor color;
    bool isQueen;

};

#endif //PIECE_HPP
