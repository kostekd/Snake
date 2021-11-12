#include "Field.h"
#include <iostream>

Field::Field()
{
    //NOT IMPLEMENTED loadData will be a 'constructor'
}

Field::~Field()
{
    //dtor
}

void Field::loadData(int xx, int yy) {
    if(xx >= 0 && yy >= 0) {
        x = xx;
        y = yy;
    }
    else {
        exit(0);
    }
}
void Field::printData() {
        printf("%i %i ", x, y);
        printf("\n");

}
