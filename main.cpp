#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include <vector>

#include "src/config.h"
#include "src/drawing.h"
#include "src/player.h"
#include "src/mazeGen.h"
#include "src/map.h"
#include "src/rayCasting.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(width, height), "it`s real 3D game!");

    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / static_cast<float>(fps));
    sf::Time elapsedTime;

    sf::Font font;
    font.loadFromFile("../res/fonts/arial.ttf");

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::Red);
    fpsText.setPosition(10, 10);

    generateMaze();
    initWorldMap();

    Drawing drawing(window);
    Player player(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time elapsedTime = clock.restart();

        player.move();
        drawing.background();
        drawing.walls(player);

        elapsedTime = clock.restart();
        if (elapsedTime < timePerFrame) {
            sf::sleep(timePerFrame - elapsedTime);
            fpsText.setString(std::to_string(fps));
        } else {
            fpsText.setString(std::to_string(static_cast<int>(1.f / elapsedTime.asSeconds())));
        }
        
        window.draw(fpsText);
        window.display();
    }
}