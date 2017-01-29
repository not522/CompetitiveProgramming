#include "template.hpp"

int main() {
  string s;
  cin >> s;
  if (set<char>(s.begin(), s.end()).size() % 2 == 0) cout << "CHAT WITH HER!" << endl;
  else cout << "IGNORE HIM!" << endl;
}
