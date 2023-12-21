
#include "SpaceRace.hpp"

SpaceRace::SpaceRace() : window(new NcursesWindow()), loop(window) {}

SpaceRace::~SpaceRace()
{
    delete window;
}

void SpaceRace::run()
{
    loop.runMenu();
}
