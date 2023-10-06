#include "Shape.h"
#include <cmath>
using namespace std;

class Circle : public Shape {
    private:
        double radius_;

    public:
        Circle(point center, double radius) : Shape(center), radius_(radius) {}
        double area() const {
            return M_PI * pow(radius_, 2);
        }
        double perimeter() const {
            return M_PI * 2 * radius_;
        }
        bool contains(const point& p) const{
            return sqrt(pow(p.x - get_center().x, 2) + pow(p.y - get_center().y, 2)) <= radius_;
        }
};

class Rectangle : public Shape {
    private:
        double width_;
        double height_;
    
    public:
        Rectangle(point center, double width, double height) : Shape(center), width_(width), height_(height) {}
        double area() const {
            return width_ * height_;
        }
        double perimeter() const {
            return 2 * (width_ + height_);
        }
        bool contains(const point& p) const {
            return p.x >= get_center().x - width_ / 2 && p.x <= get_center().x + width_ / 2 && p.y >= get_center().y - height_ / 2 && p.y <= get_center().y + height_ / 2;
        }
};