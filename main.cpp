#include <SFML/Graphics.hpp>
#include <iostream>

#include "src/config.h"
#include "src/drawing.h"
#include "src/mazeGen.h"
#include "src/map.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(fps);

    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / (float)fps);
    sf::Time elapsedTime;

    generateMaze();

    std::cout << "what!" << std::endl;
    std::vector<std::pair<int, int>>& worldMap = getWorldMap();
    std::cout << worldMap.size() << std::endl;
    for (int i = 0; i < worldMap.size(); i++) {
        int x, y;
        std::tie(x, y) = worldMap[i];
        std::cout << x << ' ' << y << std::endl;
    }
    std::cout << "what?" << std::endl;

    Drawing drawing(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        drawing.background();

        elapsedTime = clock.restart();
        if (elapsedTime < timePerFrame) {
            sf::sleep(timePerFrame - elapsedTime);
        }

        window.display();
    }

    return 0;
}