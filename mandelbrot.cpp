#include "complex.h"

complex mul(complex a, complex b) {
    complex res;
    res.real = a.real * b.real - a.img * b.img;
    res.img = a.real * b.img + a.img * b.real;
    return res;
}

complex sum(complex a, complex b) {
    complex res;
    res.real = a.real + b.real;
    res.img = a.img + b.img;
    return res;    
}

void mandel(complex c, int n, complex z[]) {
    z[0].real = 0, z[0].img = 0;
    for (int i = 1; i < n; i++) {
        z[i] = sum(mul(z[i - 1], z[i - 1]), c);
    }
}

int main() {
    { complex c = { 0, 3 };
  const int n = 5;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }
  return 0;
}