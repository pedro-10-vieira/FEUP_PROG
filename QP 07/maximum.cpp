#include "show_file.h"
#include <iomanip>
using namespace std;

void maximum(const string& input_fname, const string& output_fname) {
    ifstream linha (input_fname);
    ofstream arr (output_fname);
    double max = -1001;
    size_t count = 0;
    for (string line; getline(linha, line);) {
        if (line == "") {
            count ++;
            continue;
        }
        istringstream ints (line);
        for (double num; ints >> num;) {
            if (num > max) {
                max = num;
            }
            count ++;
            arr << fixed << setprecision(3) << num << endl;
        }
    }
    arr << "count=" << count << "/max=" << fixed << setprecision(3) << max;
}

int main() {
    { maximum("p4_test1.txt", "p4_test1_out.txt");
  show_file("p4_test1_out.txt"); }
    return 0;
}