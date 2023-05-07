#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> x(n, in);
  x = x.sort().unique().adjacent_difference();
  if (x.size() == 1) {
    cout << 0 << endl;
  } else {
    cout << x.subvector(1).min() << endl;
  }
}
