#include "dp/lis.hpp"

int main() {
  int n(in);
  Vector<int> c(n, in);
  LIS<Vector<int>, int> lis(c);
  cout << n - lis.solve() << endl;
}
