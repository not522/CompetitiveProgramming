#include "cumulative_sum_1D.hpp"
#include "math/prime.hpp"

int main() {
  Prime prime(100001);
  CumulativeSum1D<int> sum(100001);
  for (int i = 1; i < 100000; i += 2) {
    if (prime.isPrime(i) && prime.isPrime((i + 1) / 2)) sum.add(i, 1);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    cout << sum.sum(l, r + 1) << endl;
  }
}
