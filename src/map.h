#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>

#include "config.h"
#include "mazeGen.h"

void initWorldMap();
std::vector<std::pair<int, int>>& getWorldMap();

#endif