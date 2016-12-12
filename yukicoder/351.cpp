#include "vector.hpp"

int main() {
  int h, w, n, x = 0, y = 0;
  cin >> h >> w >> n;
  vector<char> s(n);
  vector<int> k(n);
  for (int i = 0; i < n; ++i) cin >> s[i] >> k[i];
  reverse(s);
  reverse(k);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R' && y == k[i]) x = x ? x - 1 : w - 1;
    if (s[i] == 'C' && x == k[i]) y = y ? y - 1 : h - 1;
  }
  cout << ((x + y) % 2 ? "black" : "white") << endl;
}
