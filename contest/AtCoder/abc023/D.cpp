#include "binary_search.hpp"
#include "vector.hpp"

int main() {
  int n(in);
  Vector<int> h(n), s(n);
  read(h, s);
  auto f = [&](int64_t m) {
    Vector<int64_t> v;
    for (int i = 0; i < n; ++i) {
      v.emplace_back((m - h[i]) / s[i]);
    }
    v.sort();
    for (int i = 0; i < n; ++i) {
      if (v[i] < i || h[i] > m) {
        return false;
      }
    }
    return true;
  };
  cout << binarySearch(f, inf<int64_t>(), 0) << endl;
}
