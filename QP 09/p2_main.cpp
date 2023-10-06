#include "Date.h"
#include "Person.h"
#include <vector>
using namespace std;

void born_before(const vector<Person>& persons, const Date& date) {
    date.show();
    cout << ": ";
    for (size_t i = 0; i < persons.size(); i++) {
        if (persons[i].get_birth_date().is_before(date)) {
            persons[i].show();
            cout << " ";
        }
    }
}

int main() {
    born_before({ {"Rui",{2009,4,9}}, {"Susana",{1997,6,19}}, {"Pedro",{2018,3,10}} }, {2019,12,31});
    return 0;
}