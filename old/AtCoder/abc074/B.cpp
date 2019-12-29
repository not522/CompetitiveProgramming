#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> x(n, in);
  for (int &i : x) {
    i = min(i, k - i);
  }
  cout << 2 * x.accumulate() << endl;
}
