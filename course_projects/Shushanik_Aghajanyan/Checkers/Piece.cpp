#include <iostream>
#include <vector>
#include <cmath>
#include "Piece.hpp"

    CellColor Piece :: GetCellColor() const {
        return color;
    }

    void Piece:: SetCellColor(CellColor col) {
        color = col;
    }

    bool Piece :: IsQueen() const {
        return isQueen;
    }

    void Piece :: SetQueen(bool queen) {
        isQueen = queen;
    }

    std::string  Piece ::GetType() const {
        if (color == White) {
            return isQueen ? " WQ " : "  W ";
        } else if (color == Black) {
            return isQueen ? " BQ " : "  B ";
        } else {
            return "    ";
        }
    }

