#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in), res = inf<int>();
  Vector<int> x(n, in);
  for (int i = 1; i <= 100; ++i) {
    chmin(res, x.transform([&](int j){ return square(i - j); }).accumulate());
  }
  cout << res << endl;
}
