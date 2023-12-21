#include "NcursesWindow.hpp"
#include "../Utils/FileSystem/FileSystem.hpp"

#include <ncurses.h>

NcursesWindow::NcursesWindow()
{
    initscr();
    keypad(stdscr, true);
    noecho();
    halfdelay(2);
    curs_set(0);
}

NcursesWindow::~NcursesWindow()
{
    endwin();
}

void NcursesWindow::drawMenu(int select)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == select)
            attron(A_STANDOUT);
        else
            attroff(A_STANDOUT);
        sprintf(menuItem, "%-7s", menuSections[i]);
        mvprintw(25 + i + 1, 70 + 2, "%s", menuItem);
    }
}

void NcursesWindow::drawAuth(int select)
{
    for (int i = 0; i < 2; i++)
    {
        if (i == select)
        {
            attron(A_STANDOUT);
        }
        else
        {
            attroff(A_STANDOUT);
        }
        sprintf(authItem, "%-7s", authSections[i]);
        mvprintw(25 + i + 1, 70 + 2, "%s", authItem);
    }
}

void NcursesWindow::drawTimeSet(int select)
{
    for (int i = 0; i < 3; i++)
    {
        if (i == select)
        {
            attron(A_STANDOUT);
        }
        else
        {
            attroff(A_STANDOUT);
        }
        sprintf(timeItem, "%-7s", timeSets[i]);
        mvprintw(25 + i + 1, 70 + 2, "%s", timeItem);
    }
}

void NcursesWindow::drawText(int x, int y, std::string text) const
{
    mvprintw(x, y, "%s", text.c_str());
}

void NcursesWindow::drawBoard(const Matrix &map) const
{
    for (int i = 0; i < (int)map.size(); ++i)
    {

        move(i + 5, 5);
        for (int j = 0; j < (int)map[i].size(); ++j)
        {
            if (j == (int)map[0].size() / 2)
            {
                printw("#");
            }
            if (map[i][j] == 'S')
                printw("|%c|", map[i][j]);
            else
                printw(" %c ", map[i][j]);
        }
    }

    refresh();
}

void NcursesWindow::drawTime(int x, int y, int seconds) const
{
    const int min = seconds / 60;
    const int sec = seconds - (min * 60);
    mvprintw(x, y, "Timer [%02d:%02d]", min, sec);
}

void NcursesWindow::drawScore(int x, int y, int scores) const
{
    mvprintw(x, y, "%s", FileSystem::convert_int_to_char(scores));
}

char NcursesWindow::input() const
{
    return getch();
}

void NcursesWindow::cleanWindow() const
{
    clear();
}