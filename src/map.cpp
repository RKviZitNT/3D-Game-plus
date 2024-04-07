#include <vector>
#include <iostream>

#include "map.h"
#include "config.h"
#include "mazeGen.h"

std::vector<char>& textMap = getTextMap();
std::vector<std::pair<int, int>> worldMap;

void initWorldMap() {
    for (int j = 0; j < mapHeight; j++) {
        for (int i = 0; i < mapWidth; i++) {
            if (textMap[mapWidth * j + i] != noneSymbol) {
                if (textMap[mapWidth * j + i] == wallSymbol) {
                    worldMap.push_back({i * tile, j * tile});
                }
            }
        }
    }
}

std::vector<std::pair<int, int>>& getWorldMap() {
    return worldMap;
}