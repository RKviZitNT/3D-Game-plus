#pragma once
#include <cmath>
#include <vector>

// game
const int width = 1280;
const int height = 720;
const int halfWidth = width / 2;
const int halfHeight = height / 2;
const int tile = 100;
const int fps = 60;

// texture
const int textureWidth = 800;
const int textureHeight = 800;
const int textureScale = textureWidth / tile;

// map
const int mapWidth = 100;
const int mapHeight = 100;
const char wallSymbol = '#';
const char noneSymbol = ' ';
const char exitSymbol = 'X';
const vector<int> bioms = {0, 1};
const int minBiomSize = 4;

// ray casting
const double fov = M_PI / 3;
const double halfFov = fpv / 2;
const int numRays = width;
const int maxDepth = 20;
const double deltaAngle = fov / numRays;
const double dist = numRays / (2*tan(halfFov));
const double projCoeff = (1 * (width / numRays))* dist * tile;
const int scale = width / numRays;

// player
const std::pair<double, double> playerPos = halfWidth, halfHeight;
const double playerAngle = 30;
const double playerSpeed = 2.5f * (60 / fps);
const double playerAcceleration = 1.7d;
const double playerSens = 0.0005d;
const int playerSide = 50;