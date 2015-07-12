#include "template.hpp"

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  int res = 0, p = a[0];
  for (int i : a) {
    res += i + t - max(p, i);
    p = i + t;
  }
  cout << res << endl;
}
