#include <iostream>
using namespace std;

int main() {
    char n;
    cin >> n;
    if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z')) {
        cout << "LETTER";
        return 0;
    }

    if (n >= '0' && n <= '9') {
        cout << "DIGIT";
        return 0;
    }

    else {
        cout << "OTHER";
    }

    return 0;
}
