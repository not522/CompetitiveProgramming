#include "vector.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), s(n);
  cin >> a;
  rsort(a);
  partial_sum(a, s);
  cout << lower_bound(s, m) + 1 << endl;
}
