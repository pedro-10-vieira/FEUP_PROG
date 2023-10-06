#include "print.h"

void normalise(const string& input_fname, const string& output_fname) {
    ifstream input (input_fname);
    ofstream output (output_fname);
    for (string line; getline(input, line);) {
        line.erase(0, line.find_first_not_of(' ', 0));
        line.erase(line.find_last_not_of(' ') + 1);
        if (line.length() != 0) {
            for (char& ch : line) {
                ch = toupper(ch);
            }
            output << line << endl;
        }
    }
}

int main() {
    { normalise("p3_test1.txt", "p3_test1_out.txt"); 
  print("p3_test1_out.txt"); }
    return 0;
} 