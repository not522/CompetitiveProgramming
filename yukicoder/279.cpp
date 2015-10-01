#include "template.hpp"

int main() {
  string s;
  cin >> s;
  map<char, int> m;
  for (char c : s) ++m[c];
  cout << min(min(m['t'], m['r']), m['e'] / 2) << endl;
}
