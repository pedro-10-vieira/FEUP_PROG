#include "HanoiPuzzle.h"

int Tower::top() const {
    if (disks_.size() > 0) {
        return disks_[disks_.size() - 1];
    }
    return 0;
}

void Tower::add(int disk) {
    disks_.push_back(disk);
}

void Tower::remove() {
    if (disks_.size() > 0) {
        disks_.pop_back();
    }
}

ostream& operator<<(ostream& os, const Tower& t) {
    os << "[ ";
    for (int element : t.get_disks()) {
        os << element << ' ';
    }
    os << ']';
    return os;
}

void HanoiPuzzle::move(const vector<disk_move>& dmoves) {
    for (disk_move e : dmoves) {
        if (((towers_[e.first].top() <= towers_[e.second].top()) || (towers_[e.second].top() == 0)) && (towers_[e.first].top() != 0)) {
            towers_[e.second].add(towers_[e.first].top());
            towers_[e.first].remove();
        }
    }
}

int main() {
{ HanoiPuzzle h(10);
  h.move({ {2,0}, {2,1}, {0, 2}, {0, 0}, {0, 1}, {2, 1}, {0, 2}, {1, 0}, {1, 2}, {0, 2}, {1,2}, {2, 0} });
  cout << h << endl; }
}