#include "vector.hpp"

int main() {
  int l, n;
  cin >> l >> n;
  vector<int> w(n), v(n);
  cin >> w;
  sort(w);
  partial_sum(w, v);
  cout << upper_bound(v, l) << endl;
}
