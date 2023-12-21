
#ifndef SPACE_RACE_HPP
#define SPACE_RACE_HPP

#include "Window/NcursesWindow.hpp"
#include "EventLoop/EventLoop.hpp"

class SpaceRace
{
private:
    Window *window;
    EventLoop loop;

public:
    SpaceRace();
    ~SpaceRace();

    void run();
};

#endif // SPACE_RACE_HPP