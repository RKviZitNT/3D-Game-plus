#ifndef CONFIG_H
#define CONFIG_H

#include <cmath>

// game
const unsigned int width = 1280;
const unsigned int height = 720;
const unsigned int halfWidth = width / 2;
const unsigned int halfHeight = height / 2;
const unsigned int tile = 100;
const unsigned int fps = 60;

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
const double fov = std::acos(-1);
const double halfFov = fps / 2;
const unsigned int numRays = width;
const unsigned int maxDepth = 20;
const double deltaAngle = fov / numRays;
const double dist = numRays / (2*tan(halfFov));
const double projCoeff = (1 * (width / numRays))* dist * tile;
const unsigned int scale = width / numRays;

// player
const std::pair<int, int> playerPos = {halfWidth, halfHeight};
const double playerAngle = 30;
const double playerSpeed = 2.5f * (60 / fps);
const double playerAcceleration = 1.7f;
const double playerSens = 0.0005f;
const unsigned int playerSide = 50;

#endif