#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  cin >> a;
  rsort(a);
  auto s = partial_sum(a);
  cout << lower_bound(s, m) + 1 << endl;
}
