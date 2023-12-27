#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <sstream>
#include "Player.hpp"
#include "Board.hpp"
#include "Piece.hpp"

class CheckersGame
{
public:


    CheckersGame();
    void CreateBoard();
    void InitializeEmptyBoard();
    void SetupPlayerPieces(Player& player, CellColor color);
    void PrintBoard() const;
    void PrintBoardHeader() const;
    void PrintRowNumber(int row) const;
    void PrintRowSeparator() const;
    void PrintPlayerInfo(const Player& player) const;
    void PlayerChoice(Player& player);
    void InputPosition(std::pair<int, int>& position, const Player& player) const;
    bool IsQueenPromotion(int endX, int endY, const Player& player) const;
    void PromoteToQueen(int endX, int endY, Player& player);
    bool Move(std::pair<int, int>& start, std::pair<int, int>& end, Player& player);
    bool IsValidMove(int startX, int startY, int endX, int endY, const Player& player) const;
    bool IsWithinBoard(int startX, int startY, int endX, int endY) const;
    bool IsCellEmpty(int x, int y) const;
    bool IsGameOver() const;
    bool IsDiagonalMove(int startX, int startY, int endX, int endY) const;
    bool IsDiagonalJump(int, int, int, int, int, int) const;
    bool IsOneStepMove(int startX, int startY, int endX, int endY) const;
    bool IsPlayerPiece(int x, int y, const Player& player) const;
    bool CanPlayerMove(int startX, int startY, const Player& player) const;
    bool CanPlayerJump(int startX, int startY, const Player& player) const;
    bool IsPlayerBlocked(const Player& player) const;
    bool CanPieceMoveOrJump(int startX, int startY, const Player& player) const;
    void BeginGame();
    void StartGame();
    void EndGame();
    void DisplayWinner() const;
    void PlayerInfo(const Player& player) const;
    bool Jump(std::pair<int, int>& start, std::pair<int, int>& end, Player& player);
    bool IsValidJump(int startX, int startY, int midX, int midY, int endX, int endY, const Player& player);
    bool PerformJump(int startX, int startY, int endX, int endY, Player& player);

private:
    bool isGameOver;
     std::vector<std::vector<Piece>> board;
    Player player1;
    Player player2;
    Player winner;

};

#endif // GAME_HPP