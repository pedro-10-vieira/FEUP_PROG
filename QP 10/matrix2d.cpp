#include <vector>
#include <iostream>
using namespace std;

void show_vector(const vector<vector<int>>& v) {
  cout << "{";
  for (const auto& line : v) {
    cout << "{ ";
    for (const auto& elem : line)
      cout << elem << ' ';
    cout << "}";
  }
  cout << "}";
}

bool max_filter(vector<vector<int>> &v, int n) {
    if (n % 2 == 0 || v.size() < n) {
        return false;
    }
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = 0; j < v[i].size(); j++) {
            int maior;
        }
    }
}