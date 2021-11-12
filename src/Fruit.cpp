#include "Fruit.h"

Fruit::Fruit(int x, int y, int w, int h)
{
    if(w > 0 && h > 0 && x >= 0 && y >= 0) {
        height = h;
        width = w;
        x_Position = x;
        y_Position = y;
        fruitShape.setPosition(sf::Vector2f(x, y));
        fruitShape.setRadius(15);
        fruitShape.setFillColor(sf::Color::Green);
    }

}

Fruit::~Fruit()
{
    //dtor
}

sf::Vector2f Fruit::getPosition() {
    return sf::Vector2f(x_Position, y_Position);
}

void Fruit::voidzik() {
    printf("%i %i\n", x_Position, y_Position);
}

void Fruit::eaten(int x, int y) {
    x_Position = x;
    y_Position = y;
    fruitShape.setPosition(sf::Vector2f(x, y));

}
