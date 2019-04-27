#include "template.hpp"

int main() {
  int n;
  string c;
  cin >> n >> c;
  string s = "ABXY";
  vector<string> v;
  for (char a : s) {
    for (char b : s) v.emplace_back(string("") + a + b);
  }
  int res = numeric_limits<int>::max();
  for (const auto& a : v) {
    for (const auto& b : v) {
      int r = 0;
      for (int i = 0; i < int(c.size()); ++i) {
        if (c.substr(i, 2) == a || c.substr(i, 2) == b) ++i;
        ++r;
      }
      res = min(res, r);
    }
  }
  cout << res << endl;
}
