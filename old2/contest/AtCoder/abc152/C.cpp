#include "vector.hpp"

int main() {
  int n(in), mn = inf<int>(), res = 0;
  Vector<int> p(n, in);
  for (int i = 0; i < n; ++i) {
    if (mn > p[i]) {
      ++res;
    }
    chmin(mn, p[i]);
  }
  cout << res << endl;
}
