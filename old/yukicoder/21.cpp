#include "vector.hpp"

int main() {
  int n(in), k(in);
  (void)k;
  Vector<int> v(n, in);
  auto m = v.minmax();
  cout << m.get<1>() - m.get<0>() << endl;
}
