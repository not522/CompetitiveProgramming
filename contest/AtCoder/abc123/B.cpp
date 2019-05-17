#include "math.hpp"
#include "vector.hpp"

int main() {
  Vector<int> v(5, in);
  int s = v.transform([](int n) { return ceil(n, 10); }).accumulate();
  cout << 10 * s - ((10 - v % 10) % 10).max() << endl;
}
