#include "vector.hpp"

int main() {
  int n(in), x(in);
  Vector<int> l(n, in);
  cout << l.partial_sum().find_if([&](int i) { return i > x; }) + 1 << endl;
}
