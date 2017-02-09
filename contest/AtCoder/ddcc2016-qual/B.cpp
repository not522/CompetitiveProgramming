#include "math/basic.hpp"

int main() {
  int r, n, m;
  cin >> r >> n >> m;
  double res = 0;
  auto f = [&](double i){return 2 * sqrt(max(double(r) * r - square(clamp<double>(i, 0, n) / n * r * 2 - r), 0.));};
  for (int i = 1; i < n + m; ++i) res += max(f(i), f(i - m));
  cout << res << endl;
}
