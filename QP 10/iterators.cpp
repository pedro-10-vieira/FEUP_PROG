#include <iostream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end) {
    string str = "[ ";
    for (Itr i = start; i!= end; i++) {
        ostringstream rep;
        rep << *i;
        str += rep.str() + " ";
    }
    str += "]";
    return str;
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b) {
    int rep = 0;
    for (Itr i = start; i != end; i++) {
        if (*i == a) {
            *i = b;
            rep ++;
        }
    }
    return rep;
}

int main() {
    return 0;
}