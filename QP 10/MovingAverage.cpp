#include "MovingAverage.h"
#include <iostream>
#include <iomanip>
using namespace std;

MovingAverage::MovingAverage(std::size_t n) {
    n_ = n;
} 

void MovingAverage::update(double value) {
    values_.push_back(value);
    if (values_.size() > n_) {
        values_.pop_front();
    }
}

double MovingAverage::get() const {
    double sum = 0;
    double num = 0;
    for (double elem : values_) {
        sum += elem;
        num ++;
    }
    return sum / num;
}

int main() {
    { MovingAverage ma(2); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }
    return 0;
}