#ifndef CONFIG_H
#define CONFIG_H

#include <cmath>
#include <vector>

// game
const unsigned int width = 1600;
const unsigned int height = 900;
const unsigned int halfWidth = width / 2;
const unsigned int halfHeight = height / 2;
const unsigned int tile = 100;
const unsigned int fps = 90;
const double pi = std::acos(-1);
const double degree = pi / 180;

// texture
const unsigned int textureWidth = 800;
const unsigned int textureHeight = 800;
const unsigned int textureScale = textureWidth / tile;

// map
const unsigned int mapWidth = 20;
const unsigned int mapHeight = 20;
const char wallSymbol = '#';
const char noneSymbol = ' ';
const char exitSymbol = 'X';
const std::vector<int> bioms = {0, 1};
const unsigned int minBiomSize = 4;

// ray casting
const double fov = pi / 3;
const double halfFov = fov / 2;
const unsigned int numRays = width / 1;
const unsigned int maxDepth = 10;
const double deltaAngle = fov / numRays;
const double dist = numRays / (2*std::tan(halfFov));
const double projCoeff = (1 * (width / numRays)) * dist * tile;
const double scale = width / numRays;

// player
const std::pair<double, double> playerPos = {((mapWidth / 2) * tile) + (tile / 2), ((mapHeight / 2) * tile) + (tile / 2)};
const double playerAngle = 0 * degree;
const double playerSpeed = 2.5 * (60.0 / fps);
const double playerAcceleration = 1.7;
const double playerSens = 0.0005;
const unsigned int playerSide = 50;

#endif