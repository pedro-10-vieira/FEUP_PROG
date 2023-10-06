#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int count(const string& fname, const string& word) {
    ifstream file (fname);
    string frase = word;
    int counter = 0;
    for (char& c : frase) {
        c = tolower(c);
    }
    for (string str; file >> str;) {
        for (char& ch : str) {
            ch = tolower(ch);
        }
        if (str == frase) {
            counter ++;
        }
    }
    return counter;
}

int main() {
    cout << count("p1_test_a.txt", "THE") << '\n';
    return 0;
}