#include "vector.hpp"

int main() {
  int n(in), m(in);
  Map<Tuple<int, int>, int> k;
  for (int i = 0; i < m; ++i) {
    int a(in), b(in), c(in);
    k[makeTuple(a, b)] = c;
  }
  auto v = iota<int>(n);
  int res = 0;
  do {
    int r = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        r += k[makeTuple(v[i], v[j])];
      }
    }
    chmax(res, r);
  } while (v.next_permutation());
  cout << res << endl;
}
