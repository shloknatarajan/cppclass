#ifndef PLANE_H
#define PLANE_H
#include <string>
#include <iostream>
using namespace std;

class Plane {
    private:
        int model;
        int rows;
        int columns;
        string make;

    public:
        // constructors 
        Plane();
        Plane(const Plane &);
        Plane(int, int, int, string);

        // functions 
        void setModel(int);
        void setRows(int);
        void setColumns(int);
        void setMake(string);

        int getModel();
        int getRows();
        int getColumns();
        string getMake();

        int getTotalSeats(int, int);
        int toBook(int);
        int getYear(int);

        void printAllData();



};
#endif
