#include "math.hpp"
#include "vector.hpp"

int main() {
  int n(in), d(in), r = 0;
  auto x = Vector<int>::makeVector(in, n, d);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      auto d = x[i] - x[j];
      if (isSquare(d.inner_product(d))) {
        ++r;
      }
    }
  }
  cout << r << endl;
}
