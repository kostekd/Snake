#ifndef WONSZ_H
#define WONSZ_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Wonsz
{
    public:
        Wonsz(int, int);
        virtual ~Wonsz();

        //variables
        sf::RectangleShape head;
        char d;
        //functions
        void setThePos(int x, int y);
        sf::Vector2f getThePos();
        void drawSnake();
        void addTale();
        void voidzik();
        bool collisionAlert(sf::RenderWindow &window);

    private:
        //variables
        int width;
        int height;
        int x;
        int y;
};

#endif // WONSZ_H
