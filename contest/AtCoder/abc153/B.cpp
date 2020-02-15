#include "vector.hpp"

int main() {
  int h(in), n(in);
  Vector<int> a(n, in);
  cout << (h <= a.accumulate()) << endl;
}
