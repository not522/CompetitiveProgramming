#include "math.hpp"

int main() {
  int n(in);
  Vector<int> a(n, in), b(n, in);
  a.sort();
  b.sort();
  int c = 0;
  do {
    do {
      int r = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) ++r;
        if (a[i] < b[i]) --r;
      }
      if (r > 0) ++c;
    } while (next_permutation(b.begin(), b.end()));
  } while (next_permutation(a.begin(), a.end()));
  cout << c / pow(factorial(n), 2);
}
