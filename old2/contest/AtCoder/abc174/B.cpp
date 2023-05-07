#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in), d(in), res = 0;
  Vector<int> x(n), y(n);
  read(x, y);
  for (int i = 0; i < n; ++i) {
    if (hypot(x[i], y[i]) <= d) {
      ++res;
    }
  }
  cout << res << endl;
}
