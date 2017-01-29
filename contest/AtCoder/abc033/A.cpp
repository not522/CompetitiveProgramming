#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << (set<char>(s.begin(), s.end()).size() == 1u ? "SAME" : "DIFFERENT") << endl;
}
