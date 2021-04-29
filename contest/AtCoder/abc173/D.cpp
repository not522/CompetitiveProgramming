#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> a(n, in);
  a.rsort();
  int64_t r = 0;
  for (int i = 0; i < n - 1; ++i) {
    r += a[(i + 1) / 2];
  }
  cout << r << endl;
}
