#include "vector.hpp"

int main() {
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (i + 1 < a[i]) res += a[i] - i - 1;
  }
  cout << res << endl;
}
