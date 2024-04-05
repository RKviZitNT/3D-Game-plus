#include <SFML/Graphics.hpp>
#include "src/config.h"
#include "src/mazeGen.h"

int main() {
    unsigned int start_time =  clock();
    generate();
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << search_time;
    return 0;
}

/*class Ball {
public:
    int x, y, radius, dx, dy;
    sf::CircleShape circle;

    Ball(int x, int y, int radius) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->dx = 1;
        this->dy = 1;

        circle.setRadius(radius);
        circle.setFillColor(sf::Color::White);
        circle.setPosition(x, y);
    }

    void move() {
        if (x + 2*radius > width || x < 0)
            dx *= -1;
        if (y + 2*radius > height || y < 0)
            dy *= -1;

        x += dx;
        y += dy;

        circle.setPosition(x, y);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(360);

    sf::Clock clock; // Создаем часы
    const sf::Time timePerFrame = sf::seconds(1.f / 360.f);
    sf::Time elapsedTime;

    Ball ball(width / 2, height / 2, 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        ball.move();
        window.draw(ball.circle);

        elapsedTime = clock.restart();
        if (elapsedTime < timePerFrame) {
            sf::sleep(timePerFrame - elapsedTime);
        }

        window.display();
    }

    return 0;
}*/