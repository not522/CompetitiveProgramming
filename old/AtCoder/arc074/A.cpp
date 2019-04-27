#include "template.hpp"

int main() {
  int64_t h, w, res = numeric_limits<int64_t>::max();
  cin >> h >> w;
  for (int k = 0; k < 2; ++k) {
    if (h % 3 == 0) {
      cout << 0 << endl;
      return 0;
    }
    if (h >= 3) chmin(res, w);
    for (int i = 1; i < h; ++i) {
      auto a = i * w;
      auto b = (h - i) * (w / 2);
      auto c = (h - i) * ((w + 1) / 2);
      chmin(res, max({a, b, c}) - min({a, b, c}));
    }
    swap(h, w);
  }
  cout << res << endl;
}
