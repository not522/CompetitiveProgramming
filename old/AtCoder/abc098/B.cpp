#include "template.hpp"

int main() {
  int n, r = 0;
  string s;
  cin >> n >> s;
  for (int i = 1; i < n; ++i) {
    string x = s.substr(0, i), y = s.substr(i);
    set<char> a(x.begin(), x.end()), b(y.begin(), y.end());
    int k = 0;
    for (char c : a) k += b.count(c);
    r = max(r, k);
  }
  cout << r << endl;
}
