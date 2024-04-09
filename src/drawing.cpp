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
    fpsText.setFillColor(sf::Color::Red);
    fpsText.setPosition(10, 10);
}

void Drawing::background() {
    window.draw(sky);
    window.draw(floor);
}

void Drawing::walls(Player& player) {
    std::vector<std::vector<double>> wallsCopy = rayCasting(player);
    for (int i = 0; i < wallsCopy.size(); i++) {
        int ray = static_cast<int>(wallsCopy[i][0]);
        double projHeight = wallsCopy[i][1];
        sf::RectangleShape projection(sf::Vector2f(scale, projHeight));
        projection.setPosition(sf::Vector2f(ray * scale, halfHeight - (projHeight / 2)));
        projection.setFillColor(sf::Color::Green);
        window.draw(projection);
    }
}

void Drawing::fps(int value) {
    fpsText.setString(std::to_string(value));
    window.draw(fpsText);
}