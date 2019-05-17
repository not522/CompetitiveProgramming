#include "math/prime.hpp"

int main() {
  int n(in), k(in), res = 0;
  Prime prime(n + 1);
  for (int i = 2; i <= n; ++i) {
    if (prime.primeFactor(i).size() >= k) {
      ++res;
    }
  }
  cout << res << endl;
}
