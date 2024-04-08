#include "rayCasting.h"

std::vector<std::pair<int, int>>& worldMapCopy = getWorldMap();

std::pair<int, int> mapping(int x, int y) {
    return {(x / tile) * tile, (y / tile) * tile};
}

std::vector<std::vector<double>> rayCasting(Player& player) {
    std::vector<std::vector<double>> walls;
    int xo, yo, xm, ym;
    double curAngle, sinA, cosA;
    int x, y, dx, dy, yv, xh, offset;
    double depthV, depthH, depth;
    double projHeight;
    std::pair<int, int> tileV, tileH;
    
    std::tie(xo, yo) = player.getPos();
    std::tie(xm, ym) = mapping(xo, yo);
    curAngle = player.getAngle() - halfFov;

    for (int ray = 0; ray < numRays; ray++) {
        sinA = std::sin(curAngle);
        cosA = std::cos(curAngle);
        if (sinA == 0)
            sinA = 0.000001;
        if (cosA == 0)
            cosA = 0.000001;
        
        // verticals
        if (cosA >= 0){
            x = xm + tile;
            dx = 1;
        } else {
            x = xm;
            dx = -1;
        }
        for (int i = 0; i < maxDepth; i++) {
            depthV = (x - xo) / cosA;
            yv = static_cast<int>(yo + depthV * sinA);
            tileV = mapping(x + dx, yv);

            auto it = std::find(worldMapCopy.begin(), worldMapCopy.end(), tileV);
            if (it != worldMapCopy.end()) {
                break;
            }
            x += dx * tile;
        }

        // horisontals
        if (sinA >= 0){
            y = ym + tile;
            dy = 1;
        } else {
            y = ym;
            dy = -1;
        }
        for (int i = 0; i < maxDepth; i++) {
            depthH = (y - yo) / sinA;
            xh = static_cast<int>(xo + depthH * cosA);
            tileH = mapping(xh, y + dy);

            auto it = std::find(worldMapCopy.begin(), worldMapCopy.end(), tileH);
            if (it != worldMapCopy.end()) {
                break;
            }
            y += dy * tile;
        }

        // projection
        if (depthV < depthH) {
            depth = depthV;
            offset = yv;
            //std::cout << 1;
        } else {
            depth = depthH;
            offset = xh;
            //std::cout << 0;
        }
        offset = offset % tile;

        depth *= std::cos(player.getAngle() - curAngle);
        projHeight = projCoeff / depth;

        walls.push_back(std::vector<double>{static_cast<double>(ray), projHeight});
    
        curAngle += deltaAngle;
    }

    return walls;
}