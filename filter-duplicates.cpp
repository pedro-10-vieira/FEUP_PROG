#include "print_array.h"

int filter_duplicates(const int a[], int n, int b[]) {
    int ref = a[0];
    int j = 1;
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] != ref) {
            b[j] = a[i];
            ref = a[i];
            j++;
        }
    }
    return j;
}

int main() {
    { const int n = 12;
  const int a[n] = { 1, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 3 };
  int b[n] = { 0 };
  int nf = filter_duplicates(a, n, b);
  print_array(b, nf); }
    return 0;
}