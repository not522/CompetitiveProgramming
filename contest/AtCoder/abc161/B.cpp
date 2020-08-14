#include "vector.hpp"

int main() {
  int n(in), m(in);
  Vector<int> a(n, in);
  int sum = a.accumulate();
  cout << (a.count_if([&](int k) { return k * 4 * m >= sum; }) >= m) << endl;
}
