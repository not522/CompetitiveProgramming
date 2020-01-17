#include "bisection_method.hpp"
#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> l(n, in);
  auto f = [&](double x) {
    int64_t sum = 0;
    for (int &i : l) {
      sum += floor(i / x);
    }
    return sum - 500000 + 0.5;
  };
  auto mx = bisectionMethod(f, inf<int>(), 0);
  Vector<long double> res;
  for (const int &i : l) {
    for (int j = 1;; ++j) {
      long double d = static_cast<long double>(i) / j;
      if (d < mx - 1e-9) {
        break;
      }
      res.emplace_back(d);
    }
  }
  res.rsort();
  int q(in);
  for (int i = 0; i < q; ++i) {
    int k(in);
    cout << res[k - 1] << endl;
  }
}
