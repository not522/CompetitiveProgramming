#include "vector.hpp"

int main() {
  int n(in), k(in), q(in);
  Vector<int> a(q, in), s(n, k - q);
  for (int i : a) {
    ++s[i - 1];
  }
  for (int i : s) {
    cout << (i > 0) << endl;
  }
}
