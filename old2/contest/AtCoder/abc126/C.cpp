#include "template.hpp"

int main() {
  int n(in), k(in);
  double res = 0;
  for (int i = 1; i <= n; ++i) {
    int d = i;
    double p = 1;
    while (d < k) {
      d *= 2;
      p /= 2;
    }
    res += p;
  }
  cout << res / n << endl;
}
