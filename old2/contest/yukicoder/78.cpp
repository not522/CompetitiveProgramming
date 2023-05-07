#include "string.hpp"

int main() {
  int n(in), k(in), res = 0, r = 0;
  String s(in);
  Vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = s[i] - '0';
  }
  for (int i = 0, j = 0; i < k; ++i, ++j) {
    if (r) {
      --r;
    } else {
      ++res;
    }
    if (j == n) {
      j = 0;
    }
    r += v[j];
  }
  cout << res << endl;
}
