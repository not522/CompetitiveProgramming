#include "vector.hpp"

int main() {
  int n(in);
  Vector<int64_t> a(n, in);
  a.sort();
  for (int i = 0; i < n - 1; i += 2) {
    if (a[i] + a[i + 1] < 0) {
      a[i] *= -1;
      a[i + 1] *= -1;
    }
  }
  cout << a.accumulate() << endl;
}
