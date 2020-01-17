#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> c(n, in);
  int sum = c.accumulate();
  cout << 30 * c.count_if([&](int i) { return i <= sum / 10; }) << endl;
}
