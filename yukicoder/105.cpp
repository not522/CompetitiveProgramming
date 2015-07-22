#include "template.hpp"

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < 6; ++j) {
      long double x, y;
      cin >> x >> y;
      if (0.5 + 1e-12 < x && x <= 1 + 1e-12&& y >= 0 - 1e-12) {
        cout << fixed << setprecision(15) << atan2(y, x) / M_PIl * 180 << endl;
      }
    }
  }
}
