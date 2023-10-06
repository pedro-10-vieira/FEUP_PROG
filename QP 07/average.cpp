#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double average(const string& fname) {
    ifstream med (fname);
    double cont = 0;
    double res = 0;
    while (!med.eof()) {
        double num;
        if (med >> num) {
            res += num;
            cont += 1;
            continue;
        }
        med.clear();
        med.ignore(1);
    }
    return res / cont;
}

int main() {
    { double m = average("p6_test2.txt"); 
    cout << fixed << setprecision(2) << m << '\n'; }
    return 0;
}