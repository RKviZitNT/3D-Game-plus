#include "main.h"

const int width = 800;
const int height = 600;

class Ball
{
public:
    int x, y, radius, dx, dy;

    Ball(int x, int y, int radius)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->dx = 1;
        this->dy = 1;
    }

    void move()
    {
        if (x + 2*radius > width || x < 0)
            dx *= -1;
        if (y + 2*radius > height || y < 0)
            dy *= -1;

        x += dx;
        y += dy;
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setFramerateLimit(360);

    sf::Clock clock; // Создаем часы
    const sf::Time timePerFrame = sf::seconds(1.f / 360.f);
    sf::Time elapsedTime;

    Ball ball(width / 2, height / 2, 10);
    sf::CircleShape circle(ball.radius);
    circle.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        ball.move();
        circle.setPosition(ball.x, ball.y);
        window.draw(circle);

        elapsedTime = clock.restart();
        if (elapsedTime < timePerFrame)
        {
            sf::sleep(timePerFrame - elapsedTime);
        }

        window.display();
    }

    return 0;
}