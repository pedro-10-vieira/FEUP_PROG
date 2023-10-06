#include "Date3.h"
#include <sstream>
#include <iomanip>
using namespace std;

Date::Date() {
    yyyymmdd = "00010101";
}

int Date::num_days(int year, int month) {
  int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    return 29;
  return n_days[month - 1];
}

Date::Date(int year, int month, int day) {
    if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= Date::num_days(year, month)) {
        ostringstream data;
        data << setfill('0')
            << setw(4) << year
            << setw(2) << month
            << setw(2) << day;
        yyyymmdd = data.str();
    }
    else {
        yyyymmdd = "00000000";
    }
}

int Date::get_year() const {
    return stoi(yyyymmdd.substr(0, 4));
}               

int Date::get_month() const {
    return stoi(yyyymmdd.substr(4, 2));
}  

int Date::get_day() const {
    return stoi(yyyymmdd.substr(6, 2));
}  

Date::Date(const std::string& year_month_day) {
    int year, month, day;
    char a, b;
    istringstream valid (year_month_day);
    if (valid >> year >> a >> month >> b >> day && a == '/' && b == '/' && year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= Date::num_days(year, month)) {
        ostringstream data;
        data << setfill('0')
            << setw(4) << year 
            << setw(2) << month 
            << setw(2) << day;
        yyyymmdd = data.str();
    }
    else {
        yyyymmdd = "00000000";
    }
}

bool Date::is_valid() const {
    if (yyyymmdd == "00000000") {
        return false;
    }
    return true;
}

int main() {
    Date d2("1900/02/29"); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
    return 0;
}