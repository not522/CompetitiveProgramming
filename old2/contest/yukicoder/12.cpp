#include "math/prime.hpp"
#include "set.hpp"
#include "vector.hpp"

int main() {
  Prime prime(5000000);
  int n(in);
  Vector<int> a(n, in);
  Set<int> b(a.begin(), a.end()), c;
  int res = -1, p = 1;
  for (int i = 1; i <= 5000000; ++i) {
    if (!prime.isPrime(i)) {
      continue;
    }
    bool ok = true;
    for (int ii = i; ii; ii /= 10) {
      if (b.count(ii % 10) == 0) {
        ok = false;
      }
    }
    if (ok) {
      for (int ii = i; ii; ii /= 10) {
        c.insert(ii % 10);
      }
    } else {
      if (b == c) {
        res = max(res, i - 1 - p);
      }
      p = i + 1;
      c.clear();
    }
  }
  if (b == c) {
    chmax(res, 5000000 - p);
  }
  cout << res << endl;
}
