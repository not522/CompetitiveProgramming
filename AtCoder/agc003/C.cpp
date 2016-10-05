#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  auto b = a;
  sort(b);
  for (int i = 0; i < n; i += 2) {
    if (lower_bound(b, a[i]) % 2) ++res;
  }
  cout << res << endl;
}
