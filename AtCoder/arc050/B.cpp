#include "binary_search.hpp"

int main() {
  int64_t r, b, x, y;
  cin >> r >> b >> x >> y;
  cout << binarySearch([&](int64_t k){return r >= k && b >= k && (r - k) / (x - 1) + (b - k) / (y - 1) >= k;}, 0, 1e18) << endl;
}
