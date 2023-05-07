#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> x(n, in), a(1000001);
  for (int i : x) {
    a[i] = 1;
  }
  for (int i = 0; i <= 1000000; ++i) {
    if (a[i] == 0) {
      continue;
    }
    for (int j = 2 * i; j <= 1000000; j += i) {
      if (a[j]) {
        chmax(a[j], a[i] + 1);
      }
    }
  }
  cout << a.max() << endl;
}
