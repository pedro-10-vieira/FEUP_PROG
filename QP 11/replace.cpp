#include <iostream>
#include <map>
using namespace std;

void replace(const map<char, char>& r, string& s) {
    for (char& c : s) {
        if (r.find(c) != r.end()) {
            c = r.find(c)->second;
        }
    }
}

int main() {
    { string s = "C / C++ @ LEIC";
  replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
  cout << s << '\n'; }
    return 0;
}