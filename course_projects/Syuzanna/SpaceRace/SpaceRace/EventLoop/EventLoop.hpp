#ifndef EVENT_LOOP_HPP
#define EVENT_LOOP_HPP

#include "../Window/Window.hpp"
#include "../Player/Player.hpp"

class EventLoop
{
private:
    Window *window;
    bool exit = false;

    int gameDelay=60;

    enum Event
    {
        Key_Up = 3,
        Key_Down = 2,
        Key_Enter = 10,
        Key_Esc = 27,
        Key_W = 119,
        Key_S = 115
    };

public:
    EventLoop(Window *);

    void runMenu();

    void auth();
    void play(Player,Player);
    void instrunctions();
    void options();
    void records();

    void sign_in();
};

#endif // EVENT_LOOP_HPP