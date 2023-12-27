#include<iostream>
#include <sstream>

#include "const.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "InputHandler.hpp"



CheckersGame::CheckersGame() : isGameOver(false) {
    BeginGame();
}

void CheckersGame::StartGame()
{
    while (!IsGameOver())
    {

        PlayerChoice(player1);
        PlayerChoice(player2);
    }
    EndGame();

    DisplayWinner();
}

void CheckersGame::PlayerChoice(Player &player) {
    bool validStep = false;

    while (!validStep) {
    std::pair<int, int> currentPosition;
    std::pair<int, int> newPosition;

    std::cout << player.GetPlayerName() << "'s turn:\n";
    InputPosition(currentPosition, player);
    InputPosition(newPosition, player);

        std::string step;
        step += InputHandler::getStringInput("(M)ove or (J)ump: ");

        switch (step[0]) {
            case 'M':
                validStep = Move(currentPosition, newPosition, player);
                break;
            case 'J':
                validStep = Jump(currentPosition, newPosition, player);
                break;
            default:
                std::cout << "Invalid choice. Please enter 'M' for move or 'J' for jump.\n";
                break;
        }
    }

}

bool CheckersGame::Move(std::pair<int, int>& start, std::pair<int, int>& end, Player& player) {
    int startX = start.first - 1;
    int startY = start.second - 1;
    int endX = end.first - 1;
    int endY = end.second - 1;

    if (CanPlayerMove(startX, startY, player)) {
        if (IsValidMove(startX, startY, endX, endY, player)) {
            board[endX][endY].SetCellColor(player.GetPlayerColor());
            if (board[startX][startY].IsQueen()) {
                board[endX][endY].SetQueen(true);
            }
            board[startX][startY].SetCellColor(Empty);
            board[startX][startY].SetQueen(false);

            // Check for queen promotion after the move
            if (IsQueenPromotion(endX, endY, player)) {
                PromoteToQueen(endX, endY, player);
            }
            system("clear");
            PrintBoard();
            return true; 
        }
        else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
    else {
        std::cout << "No valid move available. Try again.\n";
    }

    return false; 
}

bool CheckersGame::CanPlayerMove(int startX, int startY, const Player &player) const
{
    int directions[] = {-1, 1};
    for (int dirX : directions)
    {
        for (int dirY : directions)
        {
            int endX = startX + dirX;
            int endY = startY + dirY;
            if (endX >= 0 && endX < Row && endY >= 0 && endY < Column)
            {
                if (IsCellEmpty(endX, endY))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CheckersGame::PerformJump(int startX, int startY, int endX, int endY, Player& player) {
    int midX = (startX + endX) / 2;
    int midY = (startY + endY) / 2;

    if (IsValidJump(startX, startY, midX, midY, endX, endY, player)) {
        board[endX][endY].SetCellColor(player.GetPlayerColor());
        if (board[startX][startY].IsQueen()) {
            board[endX][endY].SetQueen(true);
        }
        board[startX][startY].SetCellColor(Empty);
        board[midX][midY].SetCellColor(Empty);
        player.SetPlayerScore(player.GetPlayerScore() + 1);

        // Decrease the piece count of the opponent player
        Player opponent = (player == player1) ? player2 : player1;
        opponent.SetPieceCount(opponent.GetPieceCount() - 1);

        // Check if the piece needs to be promoted to a queen
        if (IsQueenPromotion(endX, endY, player)) {
            PromoteToQueen(endX, endY, player);
        }

        system("clear");
        PrintBoard();

        std::string choice;
        std::cout << "Do you want to continue jumping? (Y/N): ";
        std::cin >> choice;

        if (choice[0] == 'Y' || choice[0] == 'y') {
            int newPosition[2];
            std::cout << "Enter the new position: ";
            for (int i = 0; i < 2; ++i) {
                std::cin >> newPosition[i];
            }
            // Update for the next jump
            int newEndX = newPosition[0] - 1;
            int newEndY = newPosition[1] - 1;

            // Check if the middle cell is empty for the new jump
            int newMidX = (endX + newEndX) / 2;
            int newMidY = (endY + newEndY) / 2;
            if (IsCellEmpty(newMidX, newMidY)) {
                std::cout << "Invalid move: Middle cell is empty. Ending jump.\n";
                return false;
            }

            PerformJump(endX, endY, newEndX, newEndY, player);
        }
        else {
            std::cout << "Ending jumps.\n";
        }
        return true;
    }
    else {
        std::cout << "Invalid jump. Ending jumps.\n";
        return false;
    }
}

bool CheckersGame::IsValidMove(int startX, int startY, int endX, int endY, const Player& player) const {

    if (IsWithinBoard(startX, startY, endX, endY))
    {
        if (!IsCellEmpty(startX, startY))
        {
            if (IsPlayerPiece(startX, startY, player))
            {
                if (IsCellEmpty(endX, endY))
                {
                    if (board[startX][startY].IsQueen() && IsDiagonalMove(startX, startY, endX, endY)) {
                        return true;
                    }

                    if (IsOneStepMove(startX, startY, endX, endY))
                    {
                        if (IsDiagonalMove(startX, startY, endX, endY))
                        {
                            return true;
                        }
                        else
                        {
                            std::cout << "Invalid move: Not a diagonal move\n";
                            return false;
                        }
                    }
                    else
                    {
                        std::cout << "Invalid move: Not a one-step move\n";
                        return false;
                    }
                }
                else
                {
                    std::cout << "Invalid move: Destination is not empty\n";
                    return false;
                }
            }
            else
            {
                std::cout << "Invalid move: Not the player's piece\n";
                return false;
            }
        }
        else
        {
            std::cout << "Invalid move: There is no piece\n";
            return false;
        }
    }

    else
    {
        std::cout << "Invalid move: Out of bounds\n";
        return false;
    }
}


bool CheckersGame::Jump(std::pair<int,int>& start, std::pair<int,int>& end, Player& player)  {
    int startX = start.first - 1;
    int startY = start.second - 1;
    int endX = end.first - 1;
    int endY = end.second - 1;

    while (CanPlayerJump(startX, startY, player)) {
        if(PerformJump(startX, startY, endX, endY, player)){
            return true;
        }
        else {
            return false;
        }
    }
    return false;

}
bool CheckersGame::CanPlayerJump(int startX, int startY,const Player& player) const {

    int directions[] = {-1, 1};
    for (int dirX : directions)
    {
        for (int dirY : directions)
        {
            int midX = startX + dirX;
            int midY = startY + dirY;
            int endX = startX + 2 * dirX;
            int endY = startY + 2 * dirY;
            if (IsWithinBoard(midX,midY,endX,endY))
            {
                if (!(IsCellEmpty(midX, midY)) && IsCellEmpty(endX, endY) &&
                    (!IsPlayerPiece(midX, midY,player)))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CheckersGame::IsValidJump(int startX, int startY, int midX, int midY, int endX, int endY, const Player& player) {
    if (IsWithinBoard(startX, startY, endX, endY) && midX >= 0 && midX < 8)
    {
        if (!(IsCellEmpty(startX, startY)))
        {
            if (IsPlayerPiece(startX, startY, player))
            {
                if (IsCellEmpty(endX, endY))
                {
                    if (!(IsPlayerPiece(midX, midY, player)))
                    {
                        if ((IsDiagonalJump(startX, startY, midX, midY, endX, endY)))
                        {
                            return true;
                        }
                        else
                        {
                            std::cout << "Invalid move: Not a diagonal jump\n";
                            return false;
                        }
                    }
                    else
                    {
                        std::cout << "Invalid move: In the middle is not opponent's piece\n";
                        return false;
                    }
                }
                else
                {
                    std::cout << "Invalid move: Destination is not empty\n";
                    return false;
                }
            }
            else
            {
                std::cout << "Invalid move: Not the player's piece\n";
                return false;
            }
        }
        else
        {
            std::cout << "Invalid move: There is no piece\n";
            return false;
        }
    }
    else
    {
        std::cout << "Invalid move: Out of bounds\n";
        return false;
    }
}

void CheckersGame::CreateBoard() {
    InitializeEmptyBoard();
    SetupPlayerPieces(player1, White);
    SetupPlayerPieces(player2, Black);
    PrintBoard();
}

void CheckersGame::InitializeEmptyBoard() {
    board = std::vector<std::vector<Piece>>(Row, std::vector<Piece>(Column, Piece(Empty)));
}

void CheckersGame::SetupPlayerPieces(Player& player, CellColor color) {
    int startRow = (color == White) ? 0 : Row - 3;
    int endRow = (color == White) ? 2 : Row - 1;

    for (int row = startRow; row <= endRow; ++row) {
        bool isStartingCellEmpty = (row % 2 == 0);
        int startCol = (isStartingCellEmpty) ? 1 : 0;

        for (int col = startCol; col < Column; col += 2) {
            board[row][col] = Piece(color);
        }
    }

    player.SetPlayerColor(color);
    player.SetPieceCount(12);
    PlayerInfo(player);
}

void CheckersGame::PlayerInfo(const Player& player) const {
    std::cout << "\n   " << player.GetPlayerName() << ": ";
    std::cout << "Color - " << ((player.GetPlayerColor() == White) ? "White" : "Black") << ", ";
    std::cout << "Score - " << player.GetPlayerScore() << ", ";
    std::cout << "Pieces - " << player.GetPieceCount() << "\n";
}


void CheckersGame::PrintBoard() const {
    system("clear");
    PrintBoardHeader();

    for (int row = 0; row < Row; ++row) {
        PrintRowNumber(row + 1);
        for (int col = 0; col < Column; ++col) {
            std::cout << "|" << board[row][col].GetType();
        }
        PrintRowSeparator();
    }

    PrintPlayerInfo(player1);
    PrintPlayerInfo(player2);
}


void CheckersGame::PrintBoardHeader() const {
    std::cout << "\n\n\n                     |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |"
              << "\n                     |---------------------------------------|"
              << "\n                    ";
}

void CheckersGame::PrintRowNumber(int row) const {
    std::cout << row;
}

void CheckersGame::PrintRowSeparator() const {
    std::cout << "|\n                   "
              << "--|---------------------------------------|"
              << "\n                    ";
}

void CheckersGame::PrintPlayerInfo(const Player& player) const {
    std::string playerInfo = player.GetPlayerName() + ":";

    switch (player.GetPlayerColor()) {
        case White: playerInfo += "White"; break;
        case Black: playerInfo += "Black"; break;
    }

    std::cout << playerInfo << "          Score:" << player.GetPlayerScore() << "\n                    ";
}


void CheckersGame::InputPosition(std::pair<int, int>& position, const Player& player) const {

    position.first = InputHandler::getIntInput("Enter (x, y) coordinates: ");
    position.second = InputHandler::getIntInput("");
}



bool CheckersGame::IsQueenPromotion(int endX, int endY,const Player& player) const  {
    // Check if the piece has reached the opponent's back rank
    if ((endX == 0 && player.GetPlayerColor() == Black) ||
        (endX == Row - 1 && player.GetPlayerColor() == White)) {
        return true;
    }
    return false;
}

void CheckersGame::PromoteToQueen(int endX, int endY, Player& player) {
    // If the piece reaches the back rank, promote it to a queen
    if (IsQueenPromotion(endX, endY, player)) {
        std::cout << "Congratulations! " << player.GetPlayerName() << " has been promoted to a queen.\n";
        board[endX][endY].SetQueen(true);
    }
}


bool CheckersGame::IsWithinBoard(int startX, int startY, int endX, int endY) const {
    return startX >= 0 && startX < Row && endX >= 0 && endX < Column &&
           startY >= 0 && startY < Row && endY >= 0 && endY < Column;
}

bool CheckersGame::IsCellEmpty(int x, int y) const {
    return board[x][y].GetCellColor() == Empty;
}

bool CheckersGame::IsDiagonalMove(int startX, int startY, int endX, int endY) const {
    int deltaX = std::abs(endX - startX);
    int deltaY = std::abs(endY - startY);
    return deltaX == deltaY;
}

bool CheckersGame::IsOneStepMove(int startX, int startY, int endX, int endY) const {
    int deltaX = std::abs(endX - startX);
    int deltaY = std::abs(endY - startY);
    return deltaX == 1 || deltaY == 1;
}

bool CheckersGame::IsPlayerPiece(int x, int y, const Player& player) const {
    return board[x][y].GetCellColor() == player.GetPlayerColor();
}

bool CheckersGame::IsDiagonalJump(int startX, int startY, int midX, int midY, int endX, int endY) const {
    int deltaX1 = midX - startX;
    int deltaY1 = midY - startY;
    int deltaX2 = endX - midX;
    int deltaY2 = endY - midY;

    return (std::abs(deltaX1) == std::abs(deltaY1)) && (std::abs(deltaX2) == std::abs(deltaY2));
}

bool CheckersGame::IsPlayerBlocked(const Player& player) const {
    // Iterate through the board to find the player's pieces
    for (int row = 0; row < Row; ++row) {
        for (int col = 0; col < Column; ++col) {
            const int* position = player.GetPlayerPosition();

            // Check if the current cell contains the player's piece
            if (board[row][col].GetCellColor() == player.GetPlayerColor()) {
                if (CanPieceMoveOrJump(row, col, player)) {
                    return false;
                }
            }
        }
    }

    return true;
}


bool CheckersGame::CanPieceMoveOrJump(int startX, int startY,const Player& player) const {
    // Check if the piece can move in any direction
    if (CanPlayerMove(startX, startY, player)) {
        return true;
    }

    // Check if the piece can jump in any direction
    if (CanPlayerJump(startX, startY, player)) {
        return true;
    }

    // The piece cannot make any legal moves or jumps
    return false;
}

void CheckersGame::BeginGame() {
    std::string name;
    std::cout << "\n\n   player 1, what is your name?   ";
    std::cin >> name;
    player1.SetPlayerName(name);
    system("clear");

    std::cout << "\n\n   player 2, what is your name?   ";
    std::cin >> name;
    player2.SetPlayerName(name);
    system("clear");

    std::string colorChoice = " ";

    while (colorChoice[0] != 'W' && colorChoice[0] != 'B') {
        std::cout << "\n\n   " << player1.GetPlayerName()
            << ", do you want to be White or Black?  ";

        std::cin >> colorChoice;

        switch (colorChoice[0]) {
        case 'W':
            std::cout << "\n\n\n   " << player1.GetPlayerName()
                << " chooses White. " << player2.GetPlayerName() << " is Black.";
            player1.SetPlayerColor(White);
            player2.SetPlayerColor(Black);
            break;

        case 'B':
            std::cout << "\n\n\n   " << player1.GetPlayerName() << " chooses Black. "
                << player2.GetPlayerName() << " is White.";
            player1.SetPlayerColor(Black);
            player2.SetPlayerColor(White);
            break;

        default:
            std::cout << "\n   Invalid response. Choose White or Black.\n";
            break;
        }
    }
}

bool CheckersGame::IsGameOver() const  {
    if(IsPlayerBlocked(player1) || IsPlayerBlocked(player2)){
        return true;
    }
    if(player1.GetPlayerScore() == 12 || player2.GetPlayerScore() == 12){
        return true;
    }
    if(player1.GetPieceCount() == 0 || player2.GetPieceCount() == 0){
        return true;
    }
    return false;
}


void CheckersGame ::EndGame() 
{
    if (player1.GetPlayerScore() == 12 || player2.GetPieceCount() == 0)
    {
        winner = player1;
    }
    else if (player2.GetPlayerScore() == 12 || player1.GetPieceCount() == 0)
    {
        winner = player2;
    }
    else if (IsPlayerBlocked(player1))
    {
        winner = player2;
    }
    else
    {
        winner = player1;
    }
}

void CheckersGame::DisplayWinner() const {
    system("clear"); 

    std::cout << "\n\n   Game Over!\n";
    std::cout << "   Winner: " << winner.GetPlayerName() << " (" << (winner.GetPlayerColor() == White ? "White" : "Black") << ")\n";

    char choice;
    do {
        std::cout << "\n   Press 'M' to go back to the menu: ";
        std::cin >> choice;
    } while (choice != 'M' && choice != 'm');
}