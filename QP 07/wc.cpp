#include "wc.h"
#include <iostream>
#include <fstream>
using namespace std;

wcresult wc(const string& filename) {
    ifstream file (filename);
    wcresult res = {0, 0, 0};
    for (string line; getline(file, line);) {
        res.lines ++;
        istringstream linha (line);
        for (string palavra; linha >> palavra;) {
            res.words ++;
        }
        res.bytes += line.length() + 1;
    }
    return res;
}

int main() {
    { wcresult r = wc("p2_test2.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
    return 0;
}