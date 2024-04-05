#pragma once
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>
#include <string>

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
const std::vector<int> bioms = {0, 1};
const int minBiomSize = 4;

// ray casting
const double fov = std::acos(-1);
const double halfFov = fps / 2;
const int numRays = width;
const int maxDepth = 20;
const double deltaAngle = fov / numRays;
const double dist = numRays / (2*tan(halfFov));
const double projCoeff = (1 * (width / numRays))* dist * tile;
const int scale = width / numRays;

// player
const std::pair<int, int> playerPos = {halfWidth, halfHeight};
const double playerAngle = 30;
const double playerSpeed = 2.5f * (60 / fps);
const double playerAcceleration = 1.7f;
const double playerSens = 0.0005f;
const int playerSide = 50;