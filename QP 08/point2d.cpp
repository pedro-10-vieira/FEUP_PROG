#include "Point2d.h"
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

void Point2d::translate(const Point2d& t) {
    x += t.x;
    y += t.y;
}

double Point2d::distance_to(const Point2d& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

int main() {
    { Point2d a { 1.0, 2.1 };
  a.translate({ -0.3, 0.5 });
  cout << fixed << setprecision(2) << a.get_x() << ' ' << a.get_y() << '\n'; }
    return 0;
}
