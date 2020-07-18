#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in), c = 0;
  Vector<int> p(n, in);
  for (int i = 0; i < n; ++i) {
    if (p[i] != i + 1) {
      ++c;
    }
  }
  cout << (c <= 2) << endl;
}
