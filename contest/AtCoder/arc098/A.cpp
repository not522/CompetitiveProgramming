#include "minmax.hpp"
#include "vector.hpp"

int main() {
  int n, res = numeric_limits<int>::max();
  string s;
  cin >> n >> s;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'E') a[i] = 1;
    else b[i] = 1;
  }
  reverse(a);
  a = partial_sum(a);
  b = partial_sum(b);
  reverse(a);
  for (int i = 0; i < n; ++i) chmin(res, a[i] + b[i] - 1);
  cout << res << endl;
}
