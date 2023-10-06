#include <iostream>
#include <vector>
using namespace std;

    vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

unsigned get_dec(char c) {
    for (pair<char, unsigned> elem: roman_to_int) {
        if (elem.first == c) {
            return elem.second;
        }
    }
    return 0;
}

unsigned comp_roman(char c1, char c2) {
    unsigned res;
    if (get_dec(c1) < get_dec(c2)) {
        res = get_dec(c2) - get_dec(c1);
    }
    else {
        res = get_dec(c2) + get_dec(c1);
    }
    return res;
}

unsigned roman_to_arab(const string& roman) {
    unsigned res = 0;
    char comp_let = roman[0];
    unsigned num = 0;
    for (size_t i = 0; i <= roman.size(); i++) {
        if (roman[i] == comp_let) {
            num ++;
            continue;
        }
        else {
            res += num * get_dec(comp_let);
            comp_let = roman[i];
            num = 1;
        }
        if (get_dec(comp_let) > get_dec(roman[i - 1])) {
            res += get_dec(comp_let) - 2 * get_dec(roman[i - 1]);
            comp_let = roman[i + 1];
            num = 0;
        }
    }
    return res;
}

int main() {  
    { string r = "MMMCMXCIX"; cout << roman_to_arab(r) << '\n'; }
    return 0;
}