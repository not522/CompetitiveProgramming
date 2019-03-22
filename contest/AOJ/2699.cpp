#include "vector.hpp"

int main() {
  for (int d, e; d = in, e = in, d != 0 || e != 0;) {
    auto f = [&](double a) { return abs(hypot(a, d - a) - e); };
    cout << iota<double>(d + 1).transform(f).min() << endl;
  }
}
