#include "vector.hpp"

int main() {
  vector<int> h(3), hh(3);
  string s;
  cin >> h >> s;
  for (char c : s) {
    if (c == 'G') ++hh[0];
    if (c == 'C') ++hh[1];
    if (c == 'P') ++hh[2];
  }
  int res = 0;
  for (int i = 0; i < 3; ++i) {
    int k;
    k = min(h[i], hh[(i + 1) % 3]);
    res += k * 3;
    h[i] -= k;
    hh[(i + 1) % 3] -= k;
  }
  for (int i = 0; i < 3; ++i) {
    int k;
    k = min(h[i], hh[i]);
    res += k;
    h[i] -= k;
    hh[i] -= k;
  }
  cout << res << endl;
}
