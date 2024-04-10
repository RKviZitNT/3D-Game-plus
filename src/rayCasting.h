#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "config.h"
#include "map.h"
#include "player.h"

void rayCasting(Player& player);
std::vector<std::vector<sf::Vector2f>>& getRenderedWalls();

#endif