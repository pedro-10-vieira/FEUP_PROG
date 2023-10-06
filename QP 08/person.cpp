#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Person.h"
using namespace std;

Person::Person(const std::string& name, const std::string& address, const std::string& phone) :
name_(name), address_(address), phone_(phone) { }

std::string Person::get_name() const {
    return name_;
}
std::string Person::get_address() const {
    return address_;
}
std::string Person::get_phone() const {
    return phone_;
}

void read_persons_data(const string& file_name, vector<Person>& persons) {
    ifstream in(file_name);
    for (string name; getline(in, name);) {
        string address;
        getline(in, address);
        string phone;
        getline(in, phone);
        persons.push_back({name, address, phone});
    }
}

bool comp_func(Person a, Person b) {
    return a.get_name() < b.get_name();
}

void sort_persons_by_name(vector<Person>& persons) {
    sort(persons.begin(), persons.end(), comp_func);
}

int main() {
{ vector<Person> persons;
  read_persons_data("persons-1.txt", persons);
  sort_persons_by_name(persons);
  show_persons_data(persons); }
  return 0;
}