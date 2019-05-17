#include "math.hpp"

int main() {
  int t(in);
  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < 6; ++j) {
      long double x(in), y(in);
      if (0.5 + 1e-12 < x && x <= 1 + 1e-12&& y >= 0 - 1e-12) {
        cout << atan2(y, x) / pi() * 180 << endl;
      }
    }
  }
}
