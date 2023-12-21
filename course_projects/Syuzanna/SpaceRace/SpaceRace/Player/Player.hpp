#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
private:
    std::string name;
    int score = 0;

public:
    Player() {}

    std::string getName() const;
    int getScore() const;
    void setName(std::string name);
    void setScore(int score);
};

#endif // PLAYER_HPP