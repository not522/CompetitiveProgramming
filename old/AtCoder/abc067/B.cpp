#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> l(n, in);
  l.nth_element(n - k);
  cout << l.subvector(n - k, n).accumulate() << endl;
}
