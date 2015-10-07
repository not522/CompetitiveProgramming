#include "string/to_string.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& i : a) cin >> i;
  reverse(a.begin(), a.end());
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    b[i] = max(mx - a[i] + 1, 0);
    mx = max(mx, a[i]);
  }
  reverse(b.begin(), b.end());
  cout << to_string(b) << endl;
}
