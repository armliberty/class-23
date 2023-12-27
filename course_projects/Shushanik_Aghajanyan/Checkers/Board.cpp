#include "Board.hpp"
#include "const.hpp"
#include<string>

Board::Board(int color) : cellColor(color), queen(false) {}

int Board::GetCellColor() const {
    return cellColor;
}

void Board::SetCellColor(int color) {
    cellColor = color;
}

bool Board::IsQueen() const {
    return queen;
}

void Board::SetQueen(bool isQueen) {
    queen = isQueen;
}

std::string Board::GetType() const {
    switch (cellColor) {
        case Black: return " B ";
        case White: return " W ";
        case Empty: return "   ";
        default: return ""; 
}
}
