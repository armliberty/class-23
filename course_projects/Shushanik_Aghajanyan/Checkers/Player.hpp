#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include "const.hpp"

class Player {
    public:
    Player();

    bool operator==(const Player& other) const;

    void SetPlayerName(const std::string& name);
    std::string GetPlayerName() const;
    void SetPlayerColor(CellColor color);
    CellColor GetPlayerColor() const;
    void SetPlayerScore(int score);
    int GetPlayerScore() const;
    void SetPlayerPosition(int positionX, int positionY);
    const int* GetPlayerPosition() const;
    int GetPieceCount() const;
    void SetPieceCount(int count);
    
private:
    std::string playerName;
    CellColor playerColor;
    int playerScore;
    int position[2];
    int pieceCount = 12;
};

#endif //PLAYER_HPP