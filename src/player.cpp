#include "player.h"

Player::Player() {
    std::tie(this->x, this->y) = playerPos;
    this->angle = playerAngle;

    this->speed = playerSpeed;
    this->acceleration = playerAcceleration;
    this->sens = playerSens;

    this->side = playerSide;
}

std::pair<double, double> Player::getPos() {
    return {x, y};
}

double Player::getAngle() {
    return angle;
}

void Player::move() {
    this->sinA = std::sin(angle);
    this->cosA = std::cos(angle);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->x += speed * cosA;
        this->y += speed * sinA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->x += -speed * cosA;
        this->y += -speed * sinA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->x += speed * sinA;
        this->y += -speed * cosA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->x += -speed * sinA;
        this->y += speed * cosA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->angle -= 0.02;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->angle += 0.02;
    }
}