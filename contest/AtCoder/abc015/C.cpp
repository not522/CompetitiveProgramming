#include "vector.hpp"

bool solve(const Vector<Vector<int>> &t, int i, int x) {
  if (i == 0) {
    return x == 0;
  }
  return t[i - 1].any_of([&](int j) { return solve(t, i - 1, x ^ j); });
}

int main() {
  set_bool_name("Found", "Nothing");
  int n(in), k(in);
  cout << solve(Vector<int>::makeVector(in, n, k), n, 0) << endl;
}
