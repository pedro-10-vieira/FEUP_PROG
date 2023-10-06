#include <iostream>
using namespace std;

char* repeat(const char str[], int n) {
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        len ++;
    }
    char* res = new char[n * len + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            res[i * len + j] = str[j];
        }
    }
    res[n * len] = '\0';
    return res;   
}

int main() {
    return 0;
}