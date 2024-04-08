#include "map.h"

std::vector<char>& textMapCopy = getTextMap();
std::vector<std::pair<int, int>> worldMap;

void initWorldMap() {
    for (int j = 0; j < mapHeight; j++) {
        for (int i = 0; i < mapWidth; i++) {
            if (textMapCopy[mapWidth * j + i] != noneSymbol) {
                if (textMapCopy[mapWidth * j + i] == wallSymbol) {
                    worldMap.push_back({i * tile, j * tile});
                }
            }
        }
    }
}

std::vector<std::pair<int, int>>& getWorldMap() {
    return worldMap;
}