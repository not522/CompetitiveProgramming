#include "game/nim.hpp"

int main() {
  int n, t = 0;
  cin >> n;
  vector<int> c(n);
  for (int& i : c) {
    vector<string> s(3);
    for (auto& j : s) cin >> j;
    if (s[0][0] == '#' && s[1][1] == '#' && s[2][2] == '#') i = 2;
    else if (s[1][1] == '#' && (s[0][0] == '#' || s[2][2] == '#')) i = 1;
    for (int j = 0; j < 3; ++j) if (s[j][j] == '.') ++t;
  }
  cout << (nim(c) ^ t % 2 ? "Snuke" : "Sothe") << endl;
}
