#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/config.h"
#include "src/drawing.h"
#include "src/player.h"
#include "src/mazeGen.h"
#include "src/map.h"
#include "src/rayCasting.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(fps);

    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / static_cast<float>(fps));
    sf::Time elapsedTime;

    generateMaze();
    initWorldMap();

    Drawing drawing(window);
    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        player.move();
        drawing.background();
        drawing.walls(player);

        elapsedTime = clock.restart();
        if (elapsedTime < timePerFrame) {
            sf::sleep(timePerFrame - elapsedTime);
        }

        window.display();
    }

    return 0;
}