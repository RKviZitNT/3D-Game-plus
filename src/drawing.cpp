#include "drawing.h"
#include <iostream>

Drawing::Drawing(sf::RenderWindow& window) : window(window), sky(sf::Vector2f(width, halfHeight)), floor(sf::Vector2f(width, halfHeight)) {
    sky.setFillColor(sf::Color(135, 206, 235));
    sky.setPosition(sf::Vector2f(0, 0));

    floor.setFillColor(sf::Color(40, 40, 40));
    floor.setPosition(sf::Vector2f(0, halfHeight));

    font.loadFromFile("../res/fonts/arial.ttf");
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::Green);
    fpsText.setPosition(10, 10);
}

void Drawing::background() {
    window.draw(sky);
    window.draw(floor);
}

void Drawing::walls(Player& player) {
    std::vector<std::vector<sf::Vector2f>>& renderedWalls = getRenderedWalls();
    sf::RectangleShape projection(sf::Vector2f(0, 0));
    projection.setFillColor(sf::Color(101, 67, 33));
    for (int i = 0; i < renderedWalls.size(); i++) {
        projection.setSize(renderedWalls[i][0]);
        projection.setPosition(renderedWalls[i][1]);
        window.draw(projection);
    }
}

void Drawing::fps(int value) {
    fpsText.setString(std::to_string(value));
    window.draw(fpsText);
}