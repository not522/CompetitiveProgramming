#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << int(s.size()) / 2 - count(s.begin(), s.end(), 'p') << endl;
}
