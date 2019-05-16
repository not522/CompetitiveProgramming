#include "vector.hpp"

int main() {
  int n(in), m(in), c(in);
  Vector<int> b(m, in);
  auto a = Vector<int>::makeVector(in, n, m);
  cout << a.matmul(b).count_if([&](int i) { return i > -c; }) << endl;
}
