#include "math/mint.hpp"
#include "math/polynomial.hpp"

#include <random>

int main() {
  int n(in);
  Vector<int> l(n), r(n);
  read(l, r);
  Vector<int> q;
  for (int i = 0; i < n; ++i) {
    q.emplace_back(l[i]);
    q.emplace_back(r[i]);
  }
  q.sort();
  Mint e;
  int maxl = l.max();
  Polynomial<Mint> p0{1};
  for (int k = 0; k < n; ++k) {
    p0 *= Polynomial<Mint>({-l[k], 1}) / Mint(r[k] - l[k]);
  }
  for (int i = 0; i < 2 * n - 1; ++i) {
    int a = q[i];
    int b = q[i + 1];
    if (a == b) {
      continue;
    }
    for (int k = 0; k < n; ++k) {
      if (r[k] == a) {
        p0 /= Polynomial<Mint>({-l[k], 1}) / Mint(r[k] - l[k]);
      }
    }
    if (b <= maxl) {
      continue;
    }
    Polynomial<Mint> p = p0;
    p.differentiate();
    p *= Polynomial<Mint>({0, 1});
    p.integrate();
    e += p(Mint(b)) - p(Mint(a));
  }
  for (int i = 0; i < n; ++i) {
    e *= r[i] - l[i];
  }
  for (int i = 1; i <= n + 1; ++i) {
    e *= i;
  }
  cout << e << endl;
}
