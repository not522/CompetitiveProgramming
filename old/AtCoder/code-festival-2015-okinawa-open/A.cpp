#include "math/basic.hpp"

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  if (ceil(h, 2) * ceil(w, 2) < k) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (k && i % 2 == 0 && j % 2 == 0) {
        cout << "#";
        --k;
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
}
