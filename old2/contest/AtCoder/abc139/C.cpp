#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> h(n, in);
  int i = 0, res = 0;
  for (int j = 0; j < n; ++j) {
    if (i < j && h[j - 1] < h[j]) {
      i = j;
    }
    chmax(res, j - i);
  }
  cout << res << endl;
}
