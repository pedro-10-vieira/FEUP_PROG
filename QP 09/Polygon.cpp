#include "Polygon.h"
#include <iostream>
using namespace std;

Polygon::Polygon() {
    res = {};
}

Polygon::Polygon(vector<Point> vetor) {
    res = vetor;
}
bool Polygon::get_vertex(int ver, Point& p) const {
    if (ver > 0 && ver <= (int)res.size()) {
        p = res[ver - 1];
        return true;
    }
    return false;
}

void Polygon::add_vertex(int ver, Point p) {
    res.emplace(res.begin() + ver - 1, p);
    res[ver - 1] = p;
}

double Polygon::perimeter() const {
    double counter = 0;
    for (size_t i = 0; i < res.size() - 1; i++) {
        counter += res[i].distance_(res[i + 1]);
    }
    counter += res[0].distance_(res[res.size() - 1]);
    return counter;
}

void Polygon::show() const {
    cout << "{";
    for (size_t i = 0; i < res.size(); i++) {
        res[i].show();
    }
    cout << "}";
}