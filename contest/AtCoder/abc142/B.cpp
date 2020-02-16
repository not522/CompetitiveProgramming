#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> h(n, in);
  cout << h.count_if([&](int i) { return i >= k; }) << endl;
}
