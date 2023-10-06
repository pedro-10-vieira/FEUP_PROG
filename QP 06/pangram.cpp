#include <iostream>
using namespace std;

bool pangram(const string& s, string& m) {
    bool check = false;
    int cont = 0;
    char count_letter[26] = { 0 };
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            count_letter[s[i] - 'A'] ++;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            count_letter[s[i] - 'a'] ++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count_letter[i] == 0) {
            m.push_back('a' + i);
            cont ++;
        }
    }
    if (cont == 0) {
        check = true;
    }
    return check;
}

int main() {
    { string s = "";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
       << boolalpha << r << " \"" << m << "\"\n"; }
    return 0;
}