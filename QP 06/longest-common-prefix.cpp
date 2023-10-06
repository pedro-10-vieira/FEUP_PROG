#include <iostream>
using namespace std;
#include <vector>

string longest_prefix(const vector<string>& v) {
    string res = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        for (size_t j = 0; j < res.length(); j++) {
            if (res[j] == v[i][j]) {
                continue;
            }
            else {
                res = res.substr(0, j);
                break;
            }
        }
    }
        return res;
}

int main() {
    cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
    return 0;
}