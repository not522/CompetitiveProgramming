#include "vector.hpp"

int main() {
  int64_t b, n;
  cin >> b >> n;
  vector<int64_t> c(n);
  cin >> c;
  sort(c);
  int64_t sum = accumulate(c);
  int64_t r = c[n / 2];
  if (c[n / 2] * n > sum + b) r = (sum + b) / n;
  int64_t res = 0;
  for (auto i : c) res += abs(r - i);
  cout << res << endl;
}
