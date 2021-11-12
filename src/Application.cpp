#include "Application.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Application::Application(int h, int w, std::string n) {
    if(h > 0 && w > 0 && n != "") {
        height = h;
        width = w;
        name = n;
    }
}

Application::~Application()
{
    //...
}

void Application::createWindow(sf::RenderWindow &window) {
    //creating the window
    window.create(sf::VideoMode(width, height), name);
}

void Application::setTheFields(Field arr[30][30], const int X, const int Y) {
    int xx = 0; //xx and yy to avoid overwriting x and y;
    int yy = 0;

    for(int i=0 ; i<X ; i++) {
        for(int j=0 ; j<Y ; j++) {
            arr[i][j].x = xx;
            arr[i][j].y = yy;
            xx += 30;
        }
        printf("\n");
        xx = 0;
        yy += 30;
    }

}
