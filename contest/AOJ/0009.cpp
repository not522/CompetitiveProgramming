#include "math/prime.hpp"

int main() {
  Prime prime(1000000);
  Vector<int> sum(1000000);
  for (int i = 1; i < 1000000; ++i) {
    sum[i] = sum[i - 1] + prime.isPrime(i);
  }
  for (int n; cin >> n;) {
    cout << sum[n] << endl;
  }
}
