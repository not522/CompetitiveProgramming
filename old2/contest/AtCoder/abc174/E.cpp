#include "binary_search.hpp"
#include "vector.hpp"

int main() {
  int n(in), k(in);
  Vector<int> a(n, in);
  auto f = [&](int64_t m) { return ((a - 1) / m).accumulate() <= k; };
  cout << binarySearch(f, 1000000000, 0) << endl;
}
