#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> h(n, in);
  for (int i = 0; i < n; ++i) {
    if (i == 0 || h[i - 1] < h[i]) {
      --h[i];
    }
    if (h[i - 1] > h[i]) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
}
