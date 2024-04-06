#ifndef DRAWING_H
#define DRAWING_H

class Drawing {
private:
    sf::RenderWindow& window;

public:
    Drawing(sf::RenderWindow& window);

    void background();
    void walls();
};

#endif