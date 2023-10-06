#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student(const std::string& id) : id_(id) { }

string Student::get_id() const {
    return id_;
}

void Student::add(const course& c) {
    courses_.push_back(c);
}

double Student::avg() const {
    double num, den;
    for (course c : courses_) {
        num += c.credits * c.grade;
        den += c.credits;
    }
    return num / den;
}

int main() {
    { Student s("up2022003333");
  s.add({"ALGA", 4.5, 18}); s.add({"AMI", 6, 16}); s.add({"PUP", 1.5, 14});
  cout << "[" << s.get_id() << "]/";
  cout << fixed << setprecision(2) << s.avg() << endl; }
  return 0;
}