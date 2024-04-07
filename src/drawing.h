#ifndef DRAWING_H
#define DRAWING_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "config.h"
#include "player.h"
#include "rayCasting.h"

class Drawing {
private:
    sf::RenderWindow& window;
    
    sf::RectangleShape projection;

    sf::RectangleShape sky;
    sf::RectangleShape floor;

public:
    Drawing(sf::RenderWindow& window);

    void background();
    void walls(Player& player);
};

#endif