#include "Person.h"
#include <iostream>
using namespace std;

class Student : Person {
    private:
        string course_;
    
    public:
        Student(int id, const string& name, const string& course) : Person(id, name), course_(course) {}
        const string& course() const {
            return course_;
        }
        string to_string() const {
            ostringstream os;
            os << Person::to_string() << '/' << course_;
            return os.str();
        }
};

class ErasmusStudent : Student {
    private:
        string country_;

    public:
        ErasmusStudent(int id, const string& name, const string& course, const string& country) : Student(id, name, course), country_(country) {}
        const string& country() const {
            return country_;
        }
        string to_string() const {
            ostringstream oss;
            oss << Student::to_string() << '/' << country_;
            return oss.str();
        }
};

int main() {
    { Person p(125, "Marie Curie");
  Student s(126, "Ada Lovelace", "LEIC");
  ErasmusStudent es(127, "Grace Hopper", "LXPTO", "United States");
  cout << p.to_string() << ' ' << s.to_string() << ' ' << es.to_string() << '\n'; }
    return 0;
}