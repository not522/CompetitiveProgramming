#include "math/prime.hpp"
#include "multiset.hpp"
#include "vector.hpp"

int main() {
  Prime prime(10000);
  int n(in);
  Vector<int> a(n, in);
  Multiset<int> s(a.begin() + 1, a.end());
  Vector<Multiset<int>> v(10001);
  for (int i : s) {
    for (auto d : prime.divisor(i)) {
      v[d].insert(i);
    }
  }
  int p = a[0];
  while (!s.empty()) {
    int next = -1, lcm = inf<int>();
    for (auto d : prime.divisor(p)) {
      if (!v[d].empty() && chmin(lcm, p * *(v[d].begin()) / int(d))) {
        next = *(v[d].begin());
      }
    }
    cout << p << " ";
    p = next;
    s.erase(p);
    for (auto d : prime.divisor(p)) {
      v[d].erase(p);
    }
  }
  cout << p << endl;
}
