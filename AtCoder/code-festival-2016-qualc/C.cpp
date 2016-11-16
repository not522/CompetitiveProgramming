#include "vector.hpp"
#include "math/mint.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> t(n), a(n);
  cin >> t >> a;
  Mint res = 1;
  if (t[0] > a[0] || t.back() < a.back()) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    if (t[i - 1] != t[i] && t[i] > a[i]) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != a[i + 1] && t[i] < a[i]) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 1; i < n - 1; ++i) {
    if (t[i - 1] == t[i] && a[i] == a[i + 1]) res *= min(t[i], a[i]);
  }
  cout << res << endl;
}
