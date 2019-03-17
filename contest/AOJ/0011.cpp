#include "vector.hpp"

int main() {
  int w, n;
  cin >> w >> n;
  Vector<int> k = iota<int>(w);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a;
    cin.ignore();
    cin >> b;
    swap(k[a - 1], k[b - 1]);
  }
  (k + 1).output();
}
