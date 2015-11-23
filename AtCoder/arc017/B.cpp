#include "vector.hpp"

int main() {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  vector<int> a(n);
  cin >> a;
  int res = 0, p = 0;
  for(int i = 1; i < n; ++i) {
    if (a[i - 1] >= a[i]) {
      p = i;
    } else {
      if (i - p + 1 >= k) ++res;
    }
  }
  cout << res << endl;
}
