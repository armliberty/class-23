#include "Player.hpp"
#include "const.hpp"

bool Player::operator==(const Player& other) const {
    return playerName == other.playerName && playerColor == other.playerColor;
}

Player::Player() : playerScore(0) {
    position[0] = -1;
    position[1] = -1;
}

void Player::SetPlayerName(const std::string& name) {
    playerName = name;
}

std::string Player::GetPlayerName() const {
    return playerName;
}

void Player::SetPlayerColor(CellColor color) {
    playerColor = color;
}

CellColor Player::GetPlayerColor() const {
    return playerColor;
}

void Player::SetPlayerScore(int score) {
    playerScore = score;
}

int Player::GetPlayerScore() const {
    return playerScore;
}

void Player::SetPlayerPosition(int positionX, int positionY) {
    position[0] = positionX;
    position[1] = positionY;
}

const int* Player::GetPlayerPosition() const {
    return position;
}

int Player::GetPieceCount() const {
    return pieceCount;
}

void Player::SetPieceCount(int piece){
pieceCount = piece;
}

