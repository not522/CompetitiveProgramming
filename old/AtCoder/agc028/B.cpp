#include "math/mint.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  Mint np = 1, res = 0;
  for (int i = 1; i <= n; ++i) np *= i;
  vector<Mint> vm(n + 1);
  for (int i = 1; i <= n; ++i) vm[i] = np / i;
  for (int i = 1; i <= n; ++i) vm[i] += vm[i - 1];
  for (int i = 0; i < n; ++i) res += a[i] * (vm[i + 1] + vm[n - i] - vm[1]);
  cout << res << endl;
}
