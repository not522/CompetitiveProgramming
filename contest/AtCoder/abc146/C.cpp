#include "binary_search.hpp"

int d(int64_t x) {
  int res = 0;
  while (x) {
    x /= 10;
    ++res;
  }
  return res;
}

int main() {
  int64_t a(in), b(in), x(in);
  auto f = [&](int64_t y) { return a * y + b * d(y) <= x; };
  cout << min<int64_t>(binarySearch(f, 0, x / a + 1), 1000000000) << endl;
}
