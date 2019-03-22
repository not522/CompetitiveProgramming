#include "vector.hpp"

int main() {
  int w(in), n(in);
  Vector<int> k = iota<int>(w);
  for (int i = 0; i < n; ++i) {
    int a(in);
    in.ignore();
    int b(in);
    swap(k[a - 1], k[b - 1]);
  }
  (k + 1).output();
}
