#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <vector>

class Window
{
protected:
    char menuSections[5][14] = {"PLAY","INSTRUNCTIONS", "OPTIONS", "RECORDS", "QUIT"};
    char menuItem[14];

    char authSections[2][13] = {"SIGN_IN", "BACK_TO_MENU"};
    char authItem[20];

    char timeSets[3][15] = {"60 SECONDS","90 SECONDS", "120 SECONDS"};
    char timeItem[15];

    using Matrix = std::vector<std::vector<char>>;

public:
    Window() {}
    virtual ~Window() {}

    virtual void drawTime(int x, int y, int seconds) const = 0;
    virtual void drawScore(int x, int y, int scores) const = 0;
    virtual void drawMenu(int select) = 0;
    virtual void drawAuth(int select) = 0;
    virtual void drawTimeSet(int select) = 0;
    virtual void drawText(int x, int y, std::string text) const = 0;
    virtual void drawBoard(const Matrix &) const = 0;
    virtual void cleanWindow() const = 0;
    virtual char input() const = 0;
};

#endif // WINDOW_HPP