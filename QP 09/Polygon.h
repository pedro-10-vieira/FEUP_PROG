#include "Point.h"
#include <vector>
using namespace std;
#ifndef POLYGON_H
#define POLYGON_H

class Polygon{
    private:
        vector<Point> res;
    public:
        //constructors
        Polygon();
        Polygon(vector<Point> vetor);
        //accessors
        bool get_vertex(int ver, Point& p) const;
        void add_vertex(int ver, Point p);
        //member functions
        double perimeter() const;
        void show() const;
};

#endif