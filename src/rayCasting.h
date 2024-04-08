#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

#include "config.h"
#include "map.h"
#include "player.h"

std::vector<std::vector<double>> rayCasting(Player& player);

#endif