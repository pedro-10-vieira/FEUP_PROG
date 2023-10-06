#include "Date.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool operator<(Date data1, Date data2) {
    if (data1.getYear() < data2.getYear()) {
        return true;
    }
    else if (data1.getYear() == data2.getYear() && data1.getMonth() < data2.getMonth()) {
        return true;
    }
    else if (data1.getYear() == data2.getYear() && data1.getMonth() == data2.getMonth() && data1.getDay() < data2.getDay()) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& output, Date data) {
    if (data.getYear() < 10) {
        output << "000" << data.getYear();
    }
    else if (data.getYear() < 100) {
        output << "00" << data.getYear();
    }
    else if (data.getYear() < 1000) {
        output << "0" << data.getYear();
    }
    else {
        output << data.getYear();
    }
    output << "/";
    if (data.getMonth() < 10) {
        output << "0" << data.getMonth();
    }
    else {
        output << data.getMonth();
    }
    output << "/";
    if (data.getDay() < 10) {
        output << "0" << data.getDay();
    }
    else {
        output << data.getDay();
    }
    return output;
}

int main() {
    { vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
    return 0;
}