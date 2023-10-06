#include "show_file.h"

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream line (input_fname);
    ofstream output (output_fname);
    for (string str; getline(line, str);) {
        if (str.find_first_of('#') != string::npos) {
            str.erase(str.find_first_of('#'));
        }
        if (str == "") {
            continue;
        }
        istringstream nums (str);
        string initial_word;
        nums >> initial_word;
        output << initial_word;
        vector<double> v = {};
        for (double num; nums >> num;) {
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        if (v.size() % 2 != 0) {
            output << " " << fixed << setprecision(1) << v[v.size() / 2] << endl;
        }
        else {
            output << " " << fixed << setprecision(1) << 0.5 * (v[ v.size() / 2 - 1] + v[ v.size() / 2]) << endl;
        }
    }
}

int main() {
    { calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
  show_file("p5_test2_out.txt"); }
    return 0;
}