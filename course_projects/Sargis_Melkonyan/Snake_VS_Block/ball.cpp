#include "ball.hpp"


Ball::Ball(){ }

void Ball::valueDetermination(int &val){
    ballValue = val;
}

void Ball::changeCoor(){
    if(coorY != 0){
        coorY--;
    }
}