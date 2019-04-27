#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  cin >> x;
  auto y = x;
  sort(y);
  auto m1 = y[n / 2 - 1];
  auto m2 = y[n / 2];
  for (auto i : x) cout << (i <= m1 ? m2 : m1) << endl;
}
