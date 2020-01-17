#include "vector.hpp"

int main() {
  int n(in), m(in);
  auto v = iota<int>(n, 1);
  for (int i = 0; i < m; ++i) {
    int a(in);
    rotate(v.begin(), v.begin() + a - 1, v.begin() + a);
  }
  cout << v[0] << endl;
}
