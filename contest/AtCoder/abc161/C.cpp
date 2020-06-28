#include "unordered_set.hpp"

int main() {
  int64_t n(in), k(in);
  UnorderedSet<int64_t> s;
  auto res = n;
  n %= k;
  while (!s.contains(n)) {
    chmin(res, n);
    s.emplace(n);
    n = abs(n - k);
  }
  cout << res << endl;
}
