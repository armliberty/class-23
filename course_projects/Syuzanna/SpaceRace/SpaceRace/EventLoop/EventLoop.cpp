#include "EventLoop.hpp"
#include "../Utils/FileSystem/FileSystem.hpp"
#include "../GameObjects/Board.hpp"

#include <string>
#include <ctime>

EventLoop::EventLoop(Window *win) : window(win) {}

void EventLoop::runMenu()
{
    int selected = 0;
    int ch;

    while ((ch = window->input()) != Key_Esc && !exit)
    {
        window->cleanWindow();
        window->drawText(1, 62, "---------------MENU---------------");
        switch (ch)
        {
        case Event::Key_Up:
            selected--;
            if (selected < 0)
                selected = 4;
            break;
        case Event::Key_Down:
            selected++;
            if (selected > 4)
                selected = 0;
            break;
        case Event::Key_Enter:
            switch (selected)
            {
            case 0:
                auth();
                break;
            case 1:
                instrunctions();
                break;    
            case 2:
                options();
                break;
            case 3:
                records();
                break;
            case 4:
                exit = true;
                break;
            }

            break;
        }
        window->drawMenu(selected);
    }
    window->cleanWindow();
}

void EventLoop::auth()
{
    int selected = 0;
    int ch;
    bool backToMenu = false;

    while ((ch = window->input()) != Key_Esc && !backToMenu)
    {
        window->cleanWindow();
        switch (ch)
        {
        case Event::Key_Up:
            selected--;
            if (selected < 0)
                selected = 1;
            break;
        case Event::Key_Down:
            selected++;
            if (selected > 1)
                selected = 0;
            break;
        case Event::Key_Enter:
            switch (selected)
            {
            case 0:
                sign_in();
                break;
            case 1:
                backToMenu = true;
                break;
            }
        }

        window->drawAuth(selected);
    }
    window->cleanWindow();
}

void EventLoop::instrunctions()
{
    int ch;

    while ((ch = window->input()) != Key_Esc)
    {
        window->cleanWindow();
        window->drawText(1, 62, "---------------INSTRUNCTIONS---------------");
        window->drawText(13, 50, "Use the arrow keys to move your spaceship.");
        window->drawText(14, 50, "Avoid obstacles and reach the end to win. ");
        window->drawText(15, 50, "Press 'esc' to quit the game.             ");
        window->drawText(48, 50, "Press esc key to return to the main menu. ");
    }
    window->cleanWindow();
}

void EventLoop::play(Player player1, Player player2)
{
    int ch;
    Board board(player1, player2);

    while ((ch = window->input()) != Key_Esc)
    {
        window->cleanWindow();
        window->drawText(1, 62, "---------------SPACE RACE---------------");

        switch (ch)
        {
        case Event::Key_Up:
            board.movePlayer1(Direction::Up);
            break;
        case Event::Key_Down:
            board.movePlayer1(Direction::Down);
            break;
        case Event::Key_W:
            board.movePlayer2(Direction::Up);
            break;
        case Event::Key_S:
            board.movePlayer2(Direction::Down);
            break;
        }

        board.update();
        int t = std::difftime(time(0), board.startTime);
        t = gameDelay - t;
        if (t <= 0)
            window->drawText(2, 71, "YOUR TIME IS UP");
        window->drawTime (48, 3, t);
        window->drawText (48, 66, board.getPlayer1().getName());
        window->drawScore(48, 78, board.getPlayer1().getScore());
        window->drawText (48, 80, "|");
        window->drawText (48, 82, board.getPlayer2().getName());
        window->drawScore(48, 94, board.getPlayer2().getScore());
        

        window->drawBoard(board.getMatrix());
        

        FileSystem::save_points(board.getPlayer2().getScore());
        FileSystem::save_points(board.getPlayer1().getScore());
    }
    window->cleanWindow();
}

void EventLoop::options()
{
    int selected = 0;
    int ch;
    while ((ch = window->input()) != Key_Esc)
    {
        window->cleanWindow();
        window->drawText(1, 62, "---------------OPTIONS----------------");
        switch (ch)
        {
        case Event::Key_Up:
            selected--;
            if (selected < 0)
                selected = 2;
            break;
        case Event::Key_Down:
            selected++;
            if (selected > 2)
                selected = 0;
            break;
        case Event::Key_Enter:
            switch (selected)
            {
            case 0:
                gameDelay = 60;
                sign_in();
                break;
            case 1:
                gameDelay = 90;
                sign_in();
                break;
            case 2:
                gameDelay = 120;
                sign_in();
                break;    
            }
        }

        window->drawTimeSet(selected);
    }
    window->cleanWindow();
}

void EventLoop::records()
{
    int ch;

    while ((ch = window->input()) != Key_Esc)
    {
        window->cleanWindow();
        window->drawText(1, 62, "---------------RECORDS---------------");
        window->drawText(2, 20, FileSystem::read_registration());
    }
    window->cleanWindow();
}

void EventLoop::sign_in()
{

    Player player1;
    Player player2;
    char ch;
    window->drawText(1, 62, "---------------SIGN IN---------------");

    window->drawText(25, 70, "PLAYER 1'S NAME:  ");

    std::string playerName = "";

    while ((ch = window->input()) != Event::Key_Enter)
    {
        if (ch == -1)
            continue;

        playerName.push_back(ch);

        window->drawText(25, 89, playerName);

         //FileSystem::save_name(board.getPlayer1Name());
    }
    player1.setName(playerName);
    playerName = "";
    window->drawText(28, 70, "PLAYER 2'S NAME:  ");
    while ((ch = window->input()) != Event::Key_Enter)
    {
        if (ch == -1)
            continue;
        playerName.push_back(ch);

        window->drawText(28, 89, playerName);

         //FileSystem::save_name(getPlayer2().getName());
    }
    player2.setName(playerName);

    play(player1, player2);
}
