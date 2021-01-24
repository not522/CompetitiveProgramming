#include "binary_search.hpp"
#include "math/inversion_number.hpp"
#include "vector.hpp"

int main() {
  int64_t n(in);
  Vector<int> a(n, in);
  auto f = [&](int64_t k) {
    Vector<int> s(n + 1);
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= k) {
        ++t;
      } else {
        --t;
      }
      s[i + 1] = t;
    }
    return 2 * inversionNumber(s) <= n * (n + 1) / 2;
  };
  cout << binarySearch(f, 0, 1000000001) << endl;
}
