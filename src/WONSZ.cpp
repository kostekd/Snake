#include "Wonsz.h"


Wonsz::Wonsz(int w, int h){
    width = w;
    height = h;
    if(w > 0 && h > 0) {
        width = w;
        height = h;
        head.setSize(sf::Vector2f(width, height));
        head.setFillColor(sf::Color::Black);
    }
}

Wonsz::~Wonsz()
{
    //dtor
}

void Wonsz::voidzik() {
    printf("%i %i\n", x, y);
}

void Wonsz::setThePos(int xx, int yy) {
        x = xx;
        y = yy;
        head.setPosition(sf::Vector2f(x, y));
}

bool Wonsz::collisionAlert(sf::RenderWindow &window) {
    int headX = head.getPosition().x;
    int headY = head.getPosition().y;
    if(headX >= 0 && headX < window.getSize().x && headY >= 0 && headY < window.getSize().y) {
        return true;
    }
    else false;
}

sf::Vector2f Wonsz::getThePos() {
    return sf::Vector2f(x, y);
}
