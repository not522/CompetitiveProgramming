#include "template.hpp"

int main() {
  int n;
  cin >> n;
  double res = 0;
  for (int i = 0; i < n; ++i) {
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    res = max(res, a + b + c + d + e * 110 / 900);
  }
  cout << fixed << setprecision(15) << res << endl;
}
