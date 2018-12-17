#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  cin >> a;
  auto m = count_kinds(a);
  if (int(m.size()) <= k) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> x;
  for (auto i : m) x.emplace_back(i.second);
  rsort(x);
  cout << accumulate(subvector(x, k, x.size())) << endl;
}
