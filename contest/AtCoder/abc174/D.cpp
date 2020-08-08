#include "string.hpp"

int main() {
  int n(in);
  String c(in);
  Vector<int> r(n + 1), w(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    if (c[i] == 'R') {
      r[i] = r[i + 1] + 1;
    } else {
      r[i] = r[i + 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] == 'W') {
      w[i + 1] = w[i] + 1;
    } else {
      w[i + 1] = w[i];
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (r[i] == w[i]) {
      cout << r[i] << endl;
      return 0;
    }
  }
}
