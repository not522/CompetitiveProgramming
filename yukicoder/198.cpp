#include "vector.hpp"

int main() {
  long long b, n;
  cin >> b >> n;
  vector<long long> c(n);
  cin >> c;
  sort(c);
  long long sum = accumulate(c);
  long long r = c[n / 2];
  if (c[n / 2] * n > sum + b) r = (sum + b) / n;
  long long res = 0;
  for (auto i : c) res += abs(r - i);
  cout << res << endl;
}
