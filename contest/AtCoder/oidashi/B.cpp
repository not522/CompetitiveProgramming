#include "minmax.hpp"
#include "vector.hpp"
#include "container/power_set.hpp"

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> s(h, vector<int>(w));
  cin >> s;
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  if (h < w) {
    vector<vector<int>> s2(w, vector<int>(h));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        s2[j][i] = s[i][j];
      }
    }
    s = move(s2);
    for (int i = 0; i < n; ++i) swap(x[i], y[i]);
    swap(h, w);
  }
  vector<int> ng(h);
  for (int i = 0; i < n; ++i) ng[y[i]] |= 1 << x[i];
  vector<int> t(h);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      t[i] |= s[i][j] << j;
    }
  }
  int res = numeric_limits<int>::max();
  int bitmask = (1 << w) - 1;
  for (auto bit : PowerSet(w)) {
    if (ng[0] & bit) continue;
    int cnt = count_bit(int(bit));
    auto p = t;
    p[0] ^= (bit << 1 & bitmask) ^ bit ^ (bit >> 1);
    p[1] ^= bit;
    for (int i = 0; i < h - 1; ++i) {
      if (ng[i + 1] & p[i]) goto next;
      cnt += count_bit(p[i]);
      p[i + 1] ^= (p[i] << 1 & bitmask) ^ p[i] ^ (p[i] >> 1);
      if (i < h - 2) p[i + 2] ^= p[i];
    }
    if (p[h - 1]) continue;
    chmin(res, cnt);
  next:;
  }
  cout << res << endl;
}
