#ifndef NCRUSES_WINDOW_HPP
#define NCRUSES_WINDOW_HPP

#include "Window.hpp"
#include <ncurses.h>

class NcursesWindow : public Window
{
public:
    NcursesWindow();
    ~NcursesWindow();

    void drawTime(int x, int y, int seconds) const;
    void drawScore(int x, int y, int scores) const;
    void drawMenu(int select);
    void drawAuth(int select);
    void drawTimeSet(int select);
    void drawText(int x, int y, std::string text) const;
    void drawBoard(const Matrix &) const;
    void cleanWindow() const;
    char input() const;
};

#endif // NCRUSES_WINDOW_HPP