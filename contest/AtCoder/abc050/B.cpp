#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> t(n, in);
  int m(in);
  auto s = t.accumulate();
  for (int i = 0; i < m; ++i) {
    int p(in), x(in);
    cout << s - t[p - 1] + x << endl;
  }
}
