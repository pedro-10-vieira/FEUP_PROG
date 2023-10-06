#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    private:
        T1 first_;
        T2 second_;
    public:
        Pair(T1 first, T2 second) {
            first_ = first;
            second_ = second;
        }
        T1 get_first() const{
            return first_;
        }
        T2 get_second() const{
            return second_;
        }
        void show() {
            cout << "{" << first_ << "," << second_ << "}";  
        }
};

bool compare_func1(Pair<string,int> a, Pair<string,int> b) {
    if (a.get_first() < b.get_first()) {
        return true;
    }
    return false;
}

bool compare_func2(Pair<string,int> a, Pair<string,int> b) {
    if (a.get_second() < b.get_second()) {
        return true;
    }
    return false;
}

void sort_by_first(vector<Pair<string, int>>& vetor) {
    sort(vetor.begin(), vetor.end(), compare_func1);
}

void sort_by_second(vector<Pair<string, int>>& vetor) {
    sort(vetor.begin(), vetor.end(), compare_func2);
}

template <class Pair>

void show(vector<Pair>& vetor) {
    cout << "{";
    for (size_t i = 0; i < vetor.size(); i++) {
        vetor[i].show();
    }
    cout << "}";
}

int main() {
    { vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
  sort_by_first(persons);
  show(persons); cout << '\n'; }
    return 0;
}