#include "Book.h"
#include "books.cpp"
#include <iostream>
using namespace std;

int main() {
    { Book b;
  if (!(b.import("book_02.txt"))) cout << "book not found! \n";
  set<string> words = { "C++", "program", "computer", "windows" };
  b.build_index(words);
  b.show_index(); }
    return 0;
}