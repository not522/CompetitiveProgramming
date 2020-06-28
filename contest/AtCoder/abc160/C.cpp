#include "vector.hpp"

int main() {
  int k(in), n(in);
  Vector<int> a(n, in);
  a.emplace_back(a[0] + k);
  cout << k - a.adjacent_difference().subvector(1).max() << endl;
}
