#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> x(n), y(n);
  read(x, y);
  double res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res += hypot(x[i] - x[j], y[i] - y[j]);
    }
  }
  cout << res / n << endl;
}
