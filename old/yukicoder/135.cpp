#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> x(n, in);
  x = x.sort().unique().adjacent_difference();
  cout << x.subvector(1, x.size()).min() << endl;
}
