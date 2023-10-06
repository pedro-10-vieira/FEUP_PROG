#include <iostream>
#include <vector>
#include <sstream> 
#include <algorithm>
#include <string>
using namespace std;

void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

void count_words(const string& str, vector<pair<string, size_t>>& count) {
  string non_const = str;
  transform(non_const.begin(), non_const.end(), non_const.begin(), ::tolower);
  istringstream word (non_const);
  for (string palavra; word >> palavra;) {
      bool pres = false;
      for (pair<string, size_t>& element : count) {
          if (element.first == palavra) {
              element.second ++;
              pres = true;
              break;
          }
      }
      if (!pres) {
          count.push_back({palavra, 1});
      }
  }
  sort(count.begin(), count.end());
}

int main() {
  { string s = "If you want to buy  buy  if you don't want to buy  bye bye";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }
    return 0;
}