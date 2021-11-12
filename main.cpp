#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "Application.h"
#include "Wonsz.h"
#include "Fruit.h"

using namespace std;

//variables
char directions[] = {'u','d','l','r'}; ///directions (up,down,left,right)
///number of fields 30x30 = 900
const int X = 30;
const int Y = 30;
int delay = 150;
int v = 30;
int length = 1;
int offset_X = 10;
int offset_y = 10;
vector<Wonsz> snake;
Wonsz *head_p;
Wonsz *tail_p;

//functions
Field setPosition(Field arr[30][30]);
void show(vector<Wonsz> vec);
void draw(vector<Wonsz> vec, sf::RenderWindow &window);
void move(vector<Wonsz> &vec, sf::Sprite &sprite);
void update_d(vector<Wonsz> &vec);
void check(vector<Wonsz> vec);
void kill();
bool collision(vector<Wonsz> vec, sf::Transformable shape);
void locateHead(Wonsz w, sf::Sprite &sprite);
void showLenght(int l);
sf::Sprite headShape;



int main()
{
    //initialize random seed
    srand (time(NULL));

    //creating Game window
    sf::RenderWindow window;
    Application application(900, 900, "Snake The Game");
    application.createWindow(window);

    //creating backend field
    Field fields[30][30];
    application.setTheFields(fields, X, Y);

    //declaring Snake's starting parameter
    Field currentPos = setPosition(fields);
    Wonsz head(30, 30);
    head.head.setFillColor(sf::Color::Blue);
    head.setThePos(currentPos.x, currentPos.y);
    head.d = directions[0]; //going up by default
    sf::Texture texture;
    if(!texture.loadFromFile("head.png")) {
        exit(0);
    }
    headShape.setTexture(texture);
    headShape.setPosition(head.head.getPosition());

    snake.push_back(head);
    head_p = &snake[0];
    tail_p = &snake[0];

    //declaring the fruit
    Field currentFruitPos = setPosition(fields);
    Fruit fruit(currentFruitPos.x, currentFruitPos.x);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            //key pressed
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::W && snake[0].d != 'd') {
                    snake[0].d = directions[0];
                }
                else if(event.key.code == sf::Keyboard::S && snake[0].d != 'u') {
                    snake[0].d = directions[1];
                }
                else if(event.key.code == sf::Keyboard::A && snake[0].d != 'r') {
                    snake[0].d = directions[2];
                }
                else if(event.key.code == sf::Keyboard::D && snake[0].d != 'l') {
                    snake[0].d = directions[3];
                }
                 break; //breaking off the while loop to avoid multi key pressing
            }


        }


        move(snake, headShape);
        locateHead(snake[0], headShape);
        update_d(snake); //updating the directions each every iteraction

        //checking the collision between the head and the fruit
        if(snake[0].head.getPosition() == fruit.getPosition()) {
            //setting new position for the fruit after its being eaten
            currentFruitPos = setPosition(fields);
            fruit.eaten(currentFruitPos.x, currentFruitPos.y);
            //avoid spawning the fruit in the same position of snake at the moment
            if(collision(snake, fruit.fruitShape)) {
                cout<<"It happend"<<endl;
                while(collision(snake, fruit.fruitShape)) {
                    currentFruitPos = setPosition(fields);
                    fruit.eaten(currentFruitPos.x, currentFruitPos.y);
                }
            }

            //getting position of the last element
            sf::Vector2f loc = tail_p->getThePos();
            Wonsz s(30, 30);

            switch(tail_p->d){

            case 'u':
                 s.setThePos(loc.x, loc.y + 30);
                break;

            case 'd':
                 s.setThePos(loc.x, loc.y - 30);
                break;

            case 'l':
                s.setThePos(loc.x + 30, loc.y);
                break;

            case 'r':
                s.setThePos(loc.x - 30, loc.y);
                break;
            }

            // pointing to the new element as a new 'tail'
            s.d = tail_p->d;
            snake.push_back(s);
            tail_p = &snake[snake.size() - 1];
            length++;
            showLenght(length);

        }

        //if there is a collision with the head and another part of the snake
        if(!snake[0].collisionAlert(window) || collision(snake, snake[0].head)){
            kill();
            window.close();
        }

        window.clear(sf::Color::Red);
        window.draw(fruit.fruitShape);
        draw(snake, window);
        window.draw(headShape);
        window.display();
        Sleep(delay);
    }

    return 0;
}

///----------------------------
Field setPosition(Field arr[30][30]) {
    int x = rand()%30;
    int y = rand()%30;

    return arr[x][y];
}

void draw(vector<Wonsz> vec, sf::RenderWindow &window) {
    for(int i=0 ; i<vec.size() ; i++) {
        window.draw(vec[i].head);
    }


}
void move(vector<Wonsz> &vec, sf::Sprite &sprite) {
    for(int i=0 ; i<vec.size() ; i++) {
        int x = vec[i].getThePos().x;
        int y = vec[i].getThePos().y;

        switch(vec[i].d) {
        case 'u':
            y = y - v;
            vec[i].setThePos(x, y);
            break;

        case 'd':
            y = y + v;
            vec[i].setThePos(x, y);
            break;

        case 'l':
            x = x - v;
            vec[i].setThePos(x, y);
            break;

        case 'r':
            x = x + v;
            vec[i].setThePos(x, y);
            break;

        }
    }
}
void update_d(vector<Wonsz> &vec) {
    for(int i=vec.size() - 1 ; i>=0 ; i--) {
        vec[i + 1].d = vec[i].d;
    }
}

bool collision(vector<Wonsz> vec, sf::Transformable shape) {
    for(int i=1 ; i<vec.size() ; i++) {

        if(shape.getPosition() == vec[i].getThePos()){
            return true;
        }
    }

}

void kill() {
    cout<<"GAME OVER"<<endl;
}

void locateHead(Wonsz w, sf::Sprite &sprite) {
    int offset_x;
    int offset_y;
    switch(w.d) {
        case 'u':
            sprite.setRotation(0);
            offset_x = 0;
            offset_y = 0;
            break;

        case 'd':
            sprite.setRotation(180);
            offset_x = 30;
            offset_y = 30;
            break;

        case 'l':
            sprite.setRotation(270);
            offset_x = 0;
            offset_y = 30;
            break;

        case 'r':
            sprite.setRotation(90);
            offset_x = 30;
            offset_y = 0;
            break;

    }
    sprite.setPosition(w.getThePos().x + offset_x, w.getThePos().y + offset_y);
}

void showLenght(int l) {
    cout<<"Twoja dlugosc "<<l<<endl;
}





