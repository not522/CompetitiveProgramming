#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  int64_t n(in), a(in);
  Vector<int64_t> x(n, in);
  cout << (n * a == x.accumulate()) << endl;
}
