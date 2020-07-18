#include "vector.hpp"

int main() {
  int n(in), r = 0;
  Vector<int> p(n, in);
  for (int i = 0; i < n - 2; ++i) {
    if ((p[i] < p[i + 1]) == (p[i + 1] < p[i + 2])) {
      ++r;
    }
  }
  cout << r << endl;
}
