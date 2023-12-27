 #include "Menu.hpp"
 #include "InputHandler.hpp"
 #include<iostream>
 #include"Game.hpp"



void PrintMainMenu() {
    std::cout << "\n╔════════════════════════════╗\n"
              << "║      Checkers Main Menu    ║\n"
              << "╚════════════════════════════╝\n"
              << "  (P)lay Game\n"
              << "  (H)elp\n"
              << "  (E)xit Game\n"
              << "══════════════════════════════";
}

void PrintHelpMenu() {
    std::cout << "\n----- Checkers Help -----\n"
              << "The goal of the game is to capture all of your opponent's pieces or block them.\n"
              << "Players take turns moving their pieces diagonally.\n"
              << "To move a piece, enter its current position and the position you want to move it to.\n"
              << "You can jump over your opponent's pieces to capture them and score points.\n"
              << "If you reach the last row with your piece, it becomes a queen and can take more than one step.\n"
              << "The game continues until one player wins.\n"
              << "--------------------------";
}

void Menu() {
    char choice;
    do {
        system("clear");
        PrintMainMenu();
        choice = InputHandler::getStringInput("\nEnter your choice (P/H/E): ");
        system("clear");

        switch (choice) {
            case 'P': {
                CheckersGame game;
                game.CreateBoard();
                game.StartGame();
                break;
            }
            case 'H':
                PrintHelpMenu();
                InputHandler::getStringInput("\nPress Enter to return to the main menu.");
                break;

            case 'E':
                break;

            default:
                std::cout << "\nInvalid response! Please enter P, H, or E.\n";
                InputHandler::getStringInput("Press Enter to continue.");
                break;
        }
    } while (choice != 'E');
}