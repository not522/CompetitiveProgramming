#include "vector.hpp"

int main() {
  int n, t = 1;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) {
    t = a[t - 1];
    if (t == 2) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
