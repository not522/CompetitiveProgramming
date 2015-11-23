#include "template.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  double a = 30 * n + 0.5 * m;
  double b = 6 * m;
  if (a < b) swap(a, b);
  cerr << a << " " << b << endl;
  cout << fixed << setprecision(15) << min(abs(a - b), abs(360 - a + b)) << endl;
}
