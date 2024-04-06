#include <iostream>
#include <vector>
#include <random>
#include <map>

#include "mazeGen.h"
#include "config.h"

std::map<int, std::pair<int, int>> sides = {
    {0, {0, -1}},
    {1, {1, 0}},
    {2, {0, 1}},
    {3, {-1, 0}}
};

std::map<int, int> reside = {
    {0, 2},
    {1, 3},
    {2, 0},
    {3, 1}
};

std::vector<char> textMap(mapWidth*mapHeight, wallSymbol);

std::random_device rd;
std::mt19937 gen(rd());

int random(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void printMap() {
    for (int j = 0; j < mapHeight; j++) {
        for (int i = 0; i < mapWidth; i++)
        {
            std::cout << textMap[mapWidth*j+i] << ' ';
        }
        std::cout << std::endl;
    }
}

bool isWall(int x, int y) {
    if (x > 0 && x < mapWidth-1 && y > 0 && y < mapHeight-1)
        return false;
    return true;
}

bool isSpace(int x, int y) {
    if (textMap[mapWidth*y+x] == noneSymbol)
        return true;
    return false;
}

bool isPass(int x, int y, int side) {
    int dx, dy;
    int reverseSide = reside[side];
    if (isSpace(x, y))
        return false;
    for (const auto& val : sides) {
        if (val.first != reverseSide) {
            std::tie(dx, dy) = val.second;
            if (isSpace(x + dx, y + dy))
                return false;
        }
    }
    return true;
}

void generatePath(int startX, int startY) {
    int x = startX, y = startY, dx, dy;
    std::vector<std::pair<int, int>> pathHistory;
    pathHistory.push_back({x, y});

    while (!pathHistory.empty()) {
        std::tie(x, y) = pathHistory.back();
        textMap[mapWidth*y+x] = noneSymbol;
        std::vector<int> sidech = {0, 1, 2, 3};
        bool nextStep = false;

        for (int i = 0; i < 4; i++) {
            int index = random(0, sidech.size() - 1);
            int side = sidech[index];
            sidech.erase(sidech.begin() + index);

            std::tie(dx, dy) = sides[side];
            int newX = x + dx, newY = y + dy;

            if (!isWall(newX, newY) && isPass(newX, newY, side)) {
                x = newX;
                y = newY;
                nextStep = true;
                break;
            }
        }

        if (!nextStep)
            pathHistory.pop_back();
        else
            pathHistory.push_back({x, y});
        
        for (int j = -1; j < 2; j++) {
            for (int i = -1; i < 2; i++) {
                if (x != 0 && x != mapWidth-1 && y != 0 && y != mapHeight-1)
                    textMap[mapWidth*(startY+j)+(startX+i)] = noneSymbol;
            }
        }
    }

    int exitSpawn = random(0, 1);
    std::vector<int> walls;
    for (int i = 1; i < mapWidth - 2; i++) {
        walls.push_back(i);
    }

    while(!walls.empty()) {
        int index = random(0, walls.size() - 1);
        int wall = walls[index];
        walls.erase(walls.begin() + index);
        if (exitSpawn == 0) {
            if (textMap[mapWidth+wall] == noneSymbol) {
                textMap[wall] = exitSymbol;
                break;
            }
        }
        else {
            if (textMap[mapWidth*(mapHeight-2)+wall] == noneSymbol) {
                textMap[mapWidth*(mapHeight-1)+wall] = exitSymbol;
                break;
            }
        }
    }
}

void generateMaze() {
    generatePath(mapWidth / 2, mapHeight / 2);
    printMap();
}

std::vector<char>& getTextMap() {
    return textMap;
}