#include "vector.hpp"

int main() {
  setBoolName("YES", "NO");
  int n(in);
  Vector<int> x(n, in);
  x = x.sort().adjacent_difference().subvector(1).unique();
  cout << (x[0] != 0 && x.size() == 1) << endl;
}
