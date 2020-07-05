#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> v(n, in), c(n, in);
  cout << (v - c).maximum(0).accumulate() << endl;
}
