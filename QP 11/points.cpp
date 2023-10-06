#include "Point.h"

Point::Point() {
    x_ = 0;
    y_ = 0;
}

Point::Point(int x, int y) {
    x_ = x;
    y_ = y;
}

Point::Point(const Point& p) {
    x_ = p.x_;
    y_ = p.y_;
}

int Point::get_x() const {
    return x_;
}

int Point::get_y() const {
    return y_;
}

Point& Point::operator=(const Point& p) {
    x_ = p.x_;
    y_ = p.y_;
    return *this;
}

Point Point::operator+(const Point& p) const {
    return Point(x_ + p.x_, y_ + p.y_);
}

Point& Point::operator+=(const Point& p) {
    x_ += p.x_;
    y_ += p.y_;
    return *this;
}

Point Point::operator*(int v) const {
    return Point(v * x_, v * y_);
}

Point operator*(int x, const Point& p) {
    return Point(x * p.get_x(), x * p.get_y());
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.get_x() << "," << p.get_y() << ")";
    return os;
}

int main() {
    { Point a(1,1), b(0,1), c(1,0), d(1,1);
  d += c += b += a += {1,2};
  d = 2 * d * 2;
  std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    return 0;
}