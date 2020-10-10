#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> x(n), y(n);
  read(x, y);
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    res += abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
  }
  cout << res << endl;
}
