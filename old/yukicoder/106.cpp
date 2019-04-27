#include "math/prime.hpp"

int main() {
  int n, k, res = 0;
  cin >> n >> k;
  Prime prime(n + 1);
  for (int i = 2; i <= n; ++i) if (int(prime.primeFactor(i).size()) >= k) ++res;
  cout << res << endl;
}
