#include "math.hpp"

int main() {
  int n(in);
  Map<Tuple<int, int>, Vector<Tuple<int, int>>> c;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int x(in), y(in), a = floor(x, 20), b = floor(y, 20);
    bool ok = true;
    for (int i = a - 1; i <= a + 1; ++i) {
      for (int j = b - 1; j <= b + 1; ++j) {
        for (auto k : c[makeTuple(i, j)]) {
          if (pow(x - k.get<0>(), 2) + pow(y - k.get<1>(), 2) < 400) {
            ok = false;
          }
        }
      }
    }
    if (ok) {
      c[makeTuple(a, b)].emplace_back(x, y);
      ++res;
    }
  }
  cout << res << endl;
}
