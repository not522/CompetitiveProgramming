#include "minmax.hpp"

int main() {
  while (true) {
    int d, e;
    cin >> d >> e;
    if (d == 0 && e == 0) break;
    double res = numeric_limits<double>::max();
    for (int i = 0; i <= d; ++i) chmin(res, abs(hypot(i, d - i) - e));
    cout << res << endl;
  }
}
