#include "vector.hpp"

int main() {
  Vector<double> p(7);
  Vector<double> v{0,
                   1.0000000000000000,
                   1.0833333333333333,
                   1.2569444444444444,
                   1.5353009259259260,
                   1.6915991512345676,
                   2.0513639724794235};
  for (int i = 1; i <= 5; ++i) {
    p[i] = v[i + 1] - 1;
    for (int j = 1; j < i; ++j) {
      p[i] -= p[j] * v[i - j + 1];
    }
  }
  p[6] = 1 - accumulate(p.begin(), p.end() - 1, 0.);
  for (int i = 7; i <= 1000000; ++i) {
    v.emplace_back(inner_product(p.begin() + 1, p.end(), v.rbegin(), 0.) + 1);
  }
  int t(in);
  for (int i = 0; i < t; ++i) {
    cout << v[int(in)] << endl;
  }
}
