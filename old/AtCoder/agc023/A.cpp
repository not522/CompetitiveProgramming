#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  cin >> a;
  auto c = partial_sum(a);
  unordered_map<int64_t, int64_t> m;
  m[0] = 1;
  for (auto i : c) ++m[i];
  int64_t res = 0;
  for (auto i : m) res += i.second * (i.second - 1) / 2;
  cout << res << endl;
}
