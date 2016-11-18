#include "template.hpp"

int main() {
  int w, h, n, s = 0, t = 0;
  cin >> w >> h >> n;
  for (int i = 0; i < n; ++i) {
    int x, y, a;
    cin >> x >> y >> a;
    switch (a) {
    case 1: s = max(s, x); break;
    case 2: w = min(w, x); break;
    case 3: t = max(t, y); break;
    case 4: h = min(h, y); break;
    }
  }
  cout << max(w - s, 0) * max(h - t, 0) << endl;
}
