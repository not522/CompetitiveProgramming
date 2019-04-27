#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  sort(a);
  for (int i = 0; i <= n; ++i) {
    vector<int> v(n - i, 2 * i + 4 * (n - i) - 4);
    v.resize(n, 2 * i + 4 * (n - i) - 2);
    if (a == v) cout << i << " " << n - i << endl;
  }
}
