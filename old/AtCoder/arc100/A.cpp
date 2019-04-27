#include "vector.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  for (int i = 0; i < n; ++i) a[i] -= i + 1;
  nth_element(a, a.size() / 2);
  int b = a[a.size() / 2];
  int64_t res = 0;
  for (int i : a) res += abs(i - b);
  cout << res << endl;
}
