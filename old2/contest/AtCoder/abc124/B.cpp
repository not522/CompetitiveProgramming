#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> h(n, in);
  cout << (h.partial_sum([](int a, int b) { return max(a, b); }) - h).count(0)
       << endl;
}
