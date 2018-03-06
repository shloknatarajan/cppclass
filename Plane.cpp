#include "Plane.h"
#include <iostream>
#include <string>


Plane::Plane() {
    setModel(787);
    setRows(30);
    setColumns(8);
    setMake("Southwest");
}

Plane::Plane(int m, int r, int c, string name) {
    setModel(m);
    setRows(r);
    setColumns(c);
    setMake(name);
}

Plane::Plane(const Plane &a) {
    model = a.model;
    rows = a.rows;
    columns = a.columns;
    make = a.make;
}

void Plane::setModel(int m) {
    model = m;
}

void Plane::setRows(int r) {
    rows = r;
}

void Plane::setColumns(int c) {
    columns = c;
}

void Plane::setMake(string s) {
    make = s;
}

int Plane::getModel() {
    return model;
}

int Plane::getRows() {
    return rows;
}

int Plane::getColumns() {
    return columns;
}

string Plane::getMake() {
    return make;
}

int Plane::getTotalSeats(int r, int c) {
    return r * c;
}

int Plane::toBook(int totalSeats) {
    return totalSeats * 1.05;
}

int Plane::getYear(int modelNumber) {
    return ((modelNumber - 787) / 10 + 2018);
}

void Plane::printAllData() {
    cout << "Make: " << make << endl;
    cout << "Model Number: " << getModel() << endl;
    cout << "Rows: " << getRows() << endl;
    cout << "Columns: " << getColumns() << endl;
    cout << "Total Seats: " << getTotalSeats(rows, columns) << endl;
    cout << "Overbooking by: " << toBook(getTotalSeats(rows, columns)) - getTotalSeats(rows, columns) << endl;
    cout << "Estimated Year: " << getYear(getModel()) << endl;
}

int main() {
    Plane aeroplane = Plane(747, 35, 9, "Delta");
    aeroplane.printAllData();

    return 0;
}
