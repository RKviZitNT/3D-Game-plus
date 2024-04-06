#include <SFML/Graphics.hpp>

#include "config.h"
#include "drawing.h"

Drawing::Drawing(sf::RenderWindow& window) : window(window) {}

void Drawing::background() {
    sf::RectangleShape sky(sf::Vector2f(width, halfHeight));
    sky.setFillColor(sf::Color(135, 206, 235));
    sky.setPosition(0, 0);

    sf::RectangleShape floor(sf::Vector2f(width, halfHeight));
    floor.setFillColor(sf::Color(40, 40, 40));
    floor.setPosition(0, halfHeight);

    window.draw(sky);
    window.draw(floor);
}

void Drawing::walls() {
    
}