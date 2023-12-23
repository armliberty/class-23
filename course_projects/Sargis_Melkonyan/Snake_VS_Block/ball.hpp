#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <vector>

class Ball{
    public:
        int ballValue;
        int coorX;
        int coorY = 10;
        const char symbol = 'o';
        std::vector<Ball> balls;
    
        Ball();
        void valueDetermination(int &val);
        void changeCoor();
        



    private:
        int const width = 1;
        int const length = 1;       
};

#endif
