#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << (set<char>(s.begin(), s.end()).size() == s.size() ? "yes" : "no") << endl;
}
