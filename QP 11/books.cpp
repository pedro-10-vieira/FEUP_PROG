#include "Book.h"
#include <sstream>
using namespace std;

void Book::build_index(const set<string>& words) {
    for (size_t i = 0; i < book_.size(); i++) {
        for (size_t j = 0; j < book_[i].get_num_lines(); j++) {
            string linha = book_[i].get_line(j);
            istringstream line(linha);
            for (string word; line >> word;) {
                for (string str : words) {
                    if (word == str) {
                        if (index_.find(str) == index_.end()) {
                            index_.insert({str, {i + 1}});
                        }
                        else {
                            index_[str].insert(i + 1);
                        }
                    }
                }
            }
        }
    }
}