#include <string>
#include <vector>
#include "print_string.h"

void split(const string& s, vector<string>& v) {
    size_t pos = 0;
    while (pos < s.length()) {
        size_t newPos = s.find(' ', pos);
        if (newPos == string::npos) {
            newPos = s.length();
        }
        if (pos == newPos) {
            pos += 1;
        }
        else {
            v.push_back(s.substr(pos, newPos - pos));
            pos = newPos;
        }
    }
}

int main() {
  return 0;
}