#ifndef FIELD_H
#define FIELD_H


class Field
{
    public:
        Field();
        virtual ~Field();
        //functions
        void loadData(int xx, int yy);
        void printData();

    private:
        int x;
        int y;
};

#endif // FIELD_H
