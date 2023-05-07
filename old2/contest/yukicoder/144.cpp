#include "math.hpp"
#include "math/count_divisor.hpp"

int main() {
  int n(in);
  double p(in), res = 0;
  auto c = count_divisor(n);
  for (int i = 2; i <= n; ++i) {
    res += pow(1 - p, c[i] - 2);
  }
  cout << res << endl;
}
