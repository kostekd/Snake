#ifndef APPLICATION_H
#define APPLICATION_H
#include <iostream>
#include <SFML/Graphics.hpp>

struct Field {
    int x;
    int y;

};

class Application
{

    private:
        //variables
        int height;
        int width;
        std::string name;

    public:
        Application(int,int,std::string);
        virtual ~Application();
        //functions
        void createWindow(sf::RenderWindow &window);
        void setTheFields(Field arr[30][30], const int X, const int Y);


};

#endif // APPLICATION_H
