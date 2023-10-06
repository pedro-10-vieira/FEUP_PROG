#include "Polygon.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
{ Point p1, p2(0, 1), p3(1, 0), p4(1, 1);
  Polygon poly1 = vector<Point>{ p1, p2, p3 };
  poly1.add_vertex(3, p4); 
  poly1.show(); 
  cout << ' ' << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n'; }
    return 0;
}