#include "Date2.h"
#include <sstream>
using namespace std;

Date::Date() {
    year = 1;
    month = 1;
    day = 1;
}

int Date::num_days(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}

Date::Date(int year, int month, int day) {
    if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= Date::num_days(year, month)) {
        this-> year = year;
        this-> month = month;
        this-> day = day;
    }
    else {
        this-> year = 0;
        this-> month = 0;
        this-> day = 0;
    }
}

int Date::get_year() const {
    return year;
}               

int Date::get_month() const {
    return month;
}  

int Date::get_day() const {
    return day;
}  

Date::Date(const std::string& year_month_day) {
    int year, month, day;
    char a, b;
    istringstream valid (year_month_day);
    if (valid >> year >> a >> month >> b >> day && a == '/' && b == '/' && year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= Date::num_days(year, month)) {
        this-> year = year;
        this-> month = month;
        this-> day = day;
    }
    else {
        this-> year = 0;
        this-> month = 0;
        this-> day = 0;
    }
}

bool Date::is_valid() const {
    if (year == 0 || month == 0 || day == 0) {
        return false;
    }
    return true;
}

int main() {
    Date d2("1900/2/29"); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
    return 0;
}