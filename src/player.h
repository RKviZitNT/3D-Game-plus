#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "config.h"

class Player {
private:
    int side;
    double x, y, angle, speed, acceleration, sens, sinA, cosA, diff;
    bool lockMouse = true;

    sf::RenderWindow& window;

public:
    Player(sf::RenderWindow& window);
    std::pair<double, double> getPos();
    double getAngle();
    void move();
    void mouse();
    void keys();
};

#endif