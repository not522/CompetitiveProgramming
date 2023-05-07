#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> s(n, 1);
  for (int i = 0; i < k; ++i) {
    int d(in);
    Vector<int> a(d, in);
    for (int j : a) {
      s[j - 1] = 0;
    }
  }
  cout << s.accumulate() << endl;
}
