#include "Point.h"
#include <math.h>
#include <iostream>
using namespace std;

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int abs, int ord) {
    x = abs;
    y = ord;
}

int Point::get_x() const {
    return x;
}

int Point::get_y() const {
    return y;
}

void Point::show() const {
    cout << "(" << x << "," << y << ")";
}

double Point::distance_(Point b) const {
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}