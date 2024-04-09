#include "player.h"

Player::Player(sf::RenderWindow& window) : window(window) {
    std::tie(this->x, this->y) = playerPos;
    this->angle = playerAngle;

    this->moveSpeed = playerSpeed;
    this->acceleration = playerAcceleration;
    this->sens = playerSens;

    this->side = playerSide;

    this->lockMouse = true;
}

std::pair<double, double> Player::getPos() {
    return {x, y};
}

double Player::getAngle() {
    return angle;
}

void Player::move() {
    keys();
    mouse();
}

void Player::mouse() {
    if (lockMouse) {
        window.setMouseCursorVisible(false);
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (mousePos.x > 0 && mousePos.y > 0 && mousePos.x < width && mousePos.y < height) {
            diff = mousePos.x - halfWidth;
            sf::Mouse::setPosition(sf::Vector2i(halfWidth, halfHeight), window);
            this->angle += diff * sens;
        }
        if (angle > pi*2)
            this->angle -= pi*2;
        if (angle < -pi*2)
            this->angle += pi*2;
    } else {
        window.setMouseCursorVisible(true);
    }
}

void Player::keys() {
    this->sinA = std::sin(angle);
    this->cosA = std::cos(angle);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        this->speed = moveSpeed * acceleration;
    }
    else {
        this->speed = moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->x += speed * cosA;
        this->y += speed * sinA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->x += -speed * cosA;
        this->y += -speed * sinA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->x += speed * sinA;
        this->y += -speed * cosA;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->x += -speed * sinA;
        this->y += speed * cosA;
    }
}