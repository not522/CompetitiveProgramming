#include "vector.hpp"

int main() {
  int l(in), n(in);
  Vector<int> w(n, in);
  auto v = w.sort().partial_sum();
  cout << v.upper_bound(l) << endl;
}
