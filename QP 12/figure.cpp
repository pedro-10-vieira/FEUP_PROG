#include "Figure.h"
#include <vector>
#include <iostream>
using namespace std;

class Rectangle : public Figure {
    private:
        double width_;
        double height_;

    public:
        Rectangle(double x_center, double y_center, double width, double height) : Figure(x_center, y_center), width_(width), height_(height) {}
        void draw() const {
            cout << "R(" << x_center_ << "," << y_center_ << ")" << "(" << width_ << "," << height_ << ")";
        }
};

class Circle : public Figure {
    private:
        double radius_;

    public:
        Circle(double x_center, double y_center, double radius) : Figure(x_center, y_center), radius_(radius) {}
        void draw() const {
            cout << "C(" << x_center_ << "," << y_center_ << ")" << "(" << radius_ << ")";
        }
};