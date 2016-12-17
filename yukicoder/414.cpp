#include "math/prime.hpp"

int main() {
  Prime prime;
  int64_t m, p = 1;
  cin >> m;
  if (m != 1) p = prime.factor(m)[0];
  cout << p << " " << m / p << endl;
}
