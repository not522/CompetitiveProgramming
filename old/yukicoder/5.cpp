#include "vector.hpp"

int main() {
  int l, n;
  cin >> l >> n;
  vector<int> w(n);
  cin >> w;
  sort(w);
  auto v = partial_sum(w);
  cout << upper_bound(v, l) << endl;
}
