#include <iostream>
using namespace std;

bool pangram(const char s[], char m[]) {
    bool pan = true;
    int alpha[26] = {0};
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            alpha[s[i] - 'a'] ++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            alpha[s[i] - 'A'] ++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) {
            pan = false;
            m[j] = 'a' + i;
            j++;
        }
    }
    if (pan == true) {
        m[0] = '\0';
    }
    return pan;
}

int main() {
    { char s[] = "";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
     << boolalpha << r << " \"" << m << "\"\n"; }
    return 0;
}