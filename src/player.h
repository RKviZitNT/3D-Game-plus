#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include "config.h"

class Player {
private:
    int side;
    double x, y, angle, speed, acceleration, sens, sinA, cosA;
    bool lockMouse = true;
public:
    Player();
    std::pair<double, double> getPos();
    double getAngle();
    void move();
};

#endif