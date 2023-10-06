#include "print_vector.h"
#include <vector>

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] < min) {
            v[i] = min;
        }
        if (v[i] > max) {
            v[i] = max;
        }
    }
}

int main() {
    return 0;
}