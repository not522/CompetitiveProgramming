#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> d(n, in);
  d.sort();
  cout << d[n / 2] - d[n / 2 - 1] << endl;
}
