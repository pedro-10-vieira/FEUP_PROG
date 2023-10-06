#include "smatrix.h"

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    size_t i = 0;
    size_t j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].row < b[j].row) {
            r.push_back(a[i]);
            i++;
            continue;
        }
        if (a[i].row == b[j].row) {
            if (a[i].col < b[j].col) {
                r.push_back(a[i]);
                i++;
                continue;
            }
            if ((a[i].col == b[j].col) && (a[i].value + b[j].value != 0)) {
                r.push_back({a[i].row, a[i].col, a[i].value + b[j].value});
                i++;
                j++;
                continue;
            }
            if (a[i].col > b[j].col) {
                r.push_back(b[j]);
                j++;
                continue;
            }
            else {
                i++;
                j++;
                continue;
            }
        }
        if (a[i].row > b[j].row) {
            r.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        r.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        r.push_back(b[j]);
        j++;
    }   
}

int main() {
  { smatrix r;
  sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
      r);
  print(r); }
  return 0;
}