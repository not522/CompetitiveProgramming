#include "template.hpp"

int main() {
  long long b, n;
  cin >> b >> n;
  vector<long long> c(n);
  for (auto& i : c) cin >> i;
  sort(c.begin(), c.end());
  long long sum = accumulate(c.begin(), c.end(), 0ll);
  long long r = c[n / 2];
  if (c[n / 2] * n > sum + b) r = (sum + b) / n;
  long long res = 0;
  for (auto i : c) res += abs(r - i);
  cout << res << endl;
}
