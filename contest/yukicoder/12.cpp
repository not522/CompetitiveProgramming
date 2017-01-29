#include "vector.hpp"
#include "math/prime.hpp"

int main() {
  Prime prime(5000000);
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  set<int> b(a.begin(), a.end()), c;
  int res = -1, p = 1;
  for (int i = 1; i <= 5000000; ++i) {
    if (!prime.isPrime(i)) continue;
    bool ok = true;
    for (int ii = i; ii; ii /= 10) if (b.count(ii % 10) == 0) ok = false;
    if (ok) {
      for (int ii = i; ii; ii /= 10) c.insert(ii % 10);
    } else {
      if (b == c) res = max(res, i - 1 - p);
      p = i + 1;
      c = set<int>();
    }
  }
  if (b == c) res = max(res, 5000000 - p);
  cout << res << endl;
}
