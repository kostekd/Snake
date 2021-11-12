#ifndef FRUIT_H
#define FRUIT_H
#include <SFML/Graphics.hpp>
#include <iostream>

struct Field;


class Fruit
{
    public:
        Fruit(int,int,int=30,int=30);
        virtual ~Fruit();
        //variables
        sf::CircleShape fruitShape;
        //functions
        void setFruitPosition();
        sf::Vector2f getPosition();
        void eaten(int x, int y);


        void voidzik();

    private:
        int height;
        int width;
        int x_Position;
        int y_Position;
};

#endif // FRUIT_H
