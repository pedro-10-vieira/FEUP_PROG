#include <iostream>
using namespace std;

int lenght(const char *s)
{
    int len = 0;
    while (s[len] != '\0') { len ++; }
    return len;
}
const char* longest(const char* pa[]) {
    int len = 0;
    int maj_len = 0;
    int k = 0;
    for (int i = 0; pa[i] != nullptr; i++) {
        len = lenght(pa[i]);
        if (len >= maj_len) {
            maj_len = len;
            k = i;
        }
    }
    return pa[k];
}

int main() {
    { const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }
    return 0;
}